#include <unordered_map>
#include <vector>
#include <string>
#include <ctime>
#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>
#include "../include/serialize.h"
#include "../include/LRUCache.h"
#include <list>
#include <mutex>
#include <bitset>

const size_t BLOCK_SIZE = 64;              // 块大小
const size_t TOTAL_BLOCKS = 1024 * 1024 / 64; // 1MB 文件，共 16384 块
const std::string DISK_FILE = "disk.bin";


struct KVNode {
    int key;              //关键字类型改为int
    int BlockIndex;          //大文件中的偏移量
    size_t length;        //长度
    long memory_address; //内存地址
    bool in_memory;       //是否在内存中
    std::time_t timestamp; //时间戳

    KVNode(int key, int BlockIndex, size_t length, long memory_address, bool in_memory, std::time_t timestamp)
            : key(key), BlockIndex(BlockIndex), length(length), memory_address(memory_address), in_memory(in_memory), timestamp(timestamp) {}

    KVNode() : key(0), BlockIndex(0), length(0), memory_address(0), in_memory(false), timestamp(0) {}
};


class KVStore {
private:
    std::unordered_map<int, KVNode> HashMap;//节点哈希表
    std::mutex hashMapMutex; // 保护 HashMap


    //两个写缓冲大小
    std::vector<std::string> keyBuffer;
    std::vector<std::string> valueBuffer;
    std::mutex bufferMutex; // 保护 keyBuffer 和 valueBuffer

    // 位视图数组，用于跟踪块的使用情况
    std::bitset<TOTAL_BLOCKS> block_bitmap;

    long  keyBufferLength=0;
    long  ValueBufferLength=0;

    size_t bufferLimit; //缓冲区大小
    std::ofstream diskFile;
    std::string disk_filename;

    LRUCache Cache;
    int LruCapacity;
    std::mutex cacheMutex; // 保护 Cache



public:
    KVStore(size_t buffer_limit, const std::string& disk_filename,int Lru_Capacity) : bufferLimit(buffer_limit), disk_filename(disk_filename) ,LruCapacity(Lru_Capacity){
        Cache.setCapacity(LruCapacity);
        initializeDisk(disk_filename);
    }

    ~KVStore() {
        if (diskFile.is_open()) {
             flushBuffersToDisk();
            diskFile.close();
        }
    }


    void initializeDisk(std::string fileName) {
        std::ofstream disk(fileName, std::ios::binary | std::ios::app);
        disk.seekp(BLOCK_SIZE * TOTAL_BLOCKS - 1);
        disk.write("", 1);
        disk.close();
    }

    // 查找空闲块并返回其索引，若无空闲块则返回 -1
    int findFreeBlock() {
        for (size_t i = 0; i < TOTAL_BLOCKS; ++i) {
            if (!block_bitmap.test(i)) {
                return i;
            }
        }
        return -1;
    }

//    对key序列化
    static std::string serializeKey(const int key) {
        std::string serialDataKey;
        GenericMessage message = createMessageData(key);
        serialDataKey = serializeMessage(message);
        return serialDataKey;
    }

    //反序列化
    static int  deserializeKey(const std::string& serialDataKey) {
        int key;
        GenericMessage messageInt = deserializeMessage(serialDataKey);
        key = GetMessageInt(messageInt);
        return key;
    }

    //对value进行序列化,不能使用字符串
    template<typename T>
    std::string serializeValue(const T& data) {
        GenericMessage message;
        message = createMessageData(data) ;
        std::string serializedData = serializeMessage(message);
        return serializedData;
    }

    //对value进行反序列化
    template<typename T>
    void deserializeValue(const std::string& binaryData) {
        GenericMessage deserializedMessage = deserializeMessage(binaryData);
        auto value = getMessageValue(deserializedMessage);
        printMessageValue(value);
    }

    template<typename T>
    bool write(const int& key, const T& value) {
        std::string serializeValueData = serializeValue(value);
        keyBuffer.push_back(serializeKey(key));
        valueBuffer.push_back(serializeValue(value));

        HashMap[key] = KVNode(key, -1, 0, valueBuffer.size()-1, true, std::time(nullptr));

         if (keyBuffer.size() >= bufferLimit) {
             flushBuffersToDisk();
         }
         return true;
     }


    // 从内存或磁盘中读取数据的实现
    std::string read(const int& key) {
        std::string Data = Cache.get(key);
        if(Data.size() != 0){
            std::cout << "在cache中找" << std::endl;
            return Data;
        }

        if (HashMap.find(key) != HashMap.end()) {
            KVNode& node = HashMap[key];
            std::string result;
            if (node.in_memory) {
                std::cout << "在写缓冲区中找" << std::endl;
                result = valueBuffer[node.memory_address];
            } else {
                std::cout << "在磁盘中找" << std::endl;
                result = readFromDisk(node.BlockIndex, node.length);
            }
            LRUCacheNode LruNode{key,result};
            Cache.put(key,LruNode);
            return result;
        }
        return "value not here";
    }

    void flushBuffersToDisk() {
        diskFile.open(disk_filename, std::ios::binary | std::ios::in | std::ios::out);
        if (!diskFile.is_open()) {
            throw std::runtime_error("无法打开磁盘文件");
        }

        for (size_t i = 0; i < keyBuffer.size(); ++i) {
            const std::string& keyData = keyBuffer[i];
            const std::string& valueData = valueBuffer[i];

            int freeBlockIndex = findFreeBlock();
            diskFile.seekp(freeBlockIndex*BLOCK_SIZE);
            // 写入 value 到磁盘
            diskFile.write(valueData.data(), valueData.size());
            block_bitmap.set(freeBlockIndex);  // 标记为已使用
            
            int key = deserializeKey(keyData);
            HashMap[key].BlockIndex = freeBlockIndex;
            HashMap[key].in_memory = false;
            HashMap[key].length = valueData.size();

            std::cout << "Flushed key " << key << " to disk at BlockIndex " << HashMap[key].BlockIndex << "  length is " << valueData.size() <<std::endl;
        }
        diskFile.close();
        keyBuffer.clear();
        valueBuffer.clear();
    }

    std::string readFromDisk(int blockIndex, size_t length) {
        if (blockIndex < 0 || blockIndex >= TOTAL_BLOCKS || !block_bitmap.test(blockIndex)) {
            std::cerr << "Invalid block index or block is not in use!\n";
            return "";
        }

        std::ifstream inFile(disk_filename, std::ios::binary);
        if (!inFile.is_open()) {
            throw std::runtime_error("无法打开磁盘文件进行读取");
        }
        inFile.seekg(blockIndex * BLOCK_SIZE);
        char buffer[length];
        inFile.read(buffer, length);
        inFile.close();
        std::string readStr(buffer, length);
//        readValueBuffer.push_back(readStr);
        return readStr;
    }

    void Del(int& key){

    }
};





int main() {
    KVStore kvStore(1000, "disk_data.bin",5);

    std::cout << "Testing write operations..." << std::endl;

    for(int i = 0;i< 100;i++){
        kvStore.write(i,i*15);
    }



    for(int j=0;j<3;j++){
        for(int i =0;i<5;i++){
            kvStore.deserializeValue<int>(kvStore.read(i));
        }
    }

    return 0;
}
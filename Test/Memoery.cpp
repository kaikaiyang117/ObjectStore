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
#include <shared_mutex>



struct KVNode {
    int key;              //关键字类型改为int
    int DiskOffset;          //大文件中的偏移量
    size_t length;        //长度
    long memory_address; //内存地址
    bool in_memory;       //是否在内存中
    std::time_t timestamp; //时间戳

    KVNode(int key, int DiskOffset, size_t length, long memory_address, bool in_memory, std::time_t timestamp)
            : key(key), DiskOffset(DiskOffset), length(length), memory_address(memory_address), in_memory(in_memory), timestamp(timestamp) {}

    KVNode() : key(0), DiskOffset(0), length(0), memory_address(0), in_memory(false), timestamp(0) {}
};


class KVStore {
private:
    std::unordered_map<int, KVNode> HashMap;//节点哈希表
    std::shared_mutex hashMapMutex; // 保护 HashMap



    //两个写缓冲大小
    std::vector<std::string> keyBuffer;
    std::vector<std::string> valueBuffer;

    //读缓冲
//    std::vector<std::string> readValueBuffer;
//    int readValueBufferIndex = 0;

    long  keyBufferLength=0;
    long  ValueBufferLength=0;

    size_t bufferLimit; //缓冲区大小
    std::ofstream diskFile;
    std::string disk_filename;

    LRUCache Cache;
    int LruCapacity;
    std::mutex cacheMutex; // 保护 Cache
    std::shared_mutex rw_mutex;//读写锁


public:
    KVStore(size_t buffer_limit, const std::string& disk_filename,int Lru_Capacity) : bufferLimit(buffer_limit), disk_filename(disk_filename) ,LruCapacity(Lru_Capacity){
        Cache.setCapacity(LruCapacity);
    }

    ~KVStore() {
        if (diskFile.is_open()) {
             flushBuffersToDisk();
            diskFile.close();
        }
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

        std::unique_lock<std::shared_mutex> lock(rw_mutex);
        std::string serializeValueData = serializeValue(value);

        keyBuffer.push_back(serializeKey(key));
        valueBuffer.push_back(serializeValue(value));
        HashMap[key] = KVNode(key, 0, 0, valueBuffer.size()-1, true, std::time(nullptr));
         if (keyBuffer.size() >= bufferLimit) {
             flushBuffersToDisk();
         }
         return true;
     }

    void flushBuffersToDisk() {

        diskFile.open(disk_filename, std::ios::app | std::ios::binary);
        if (!diskFile.is_open()) {
            throw std::runtime_error("无法打开磁盘文件");
        }

        int offset = diskFile.tellp(); // 获取当前文件的写入偏移位置
        for (size_t i = 0; i < keyBuffer.size(); ++i) {
            const std::string& keyData = keyBuffer[i];
            const std::string& valueData = valueBuffer[i];
            // 写入 value 到磁盘
            diskFile.write(valueData.data(), valueData.size());
            int key = deserializeKey(keyData);
            HashMap[key].DiskOffset = offset;
            HashMap[key].in_memory = false;
            HashMap[key].length = valueData.size();
            offset += valueData.size();
        }
        diskFile.close();
        keyBuffer.clear();
        valueBuffer.clear();
    }

    std::string readFromDisk(long offset, size_t length) {

        std::ifstream inFile(disk_filename, std::ios::binary);
        if (!inFile.is_open()) {
            throw std::runtime_error("无法打开磁盘文件进行读取");
        }
        inFile.seekg(offset);
        char buffer[length];
        inFile.read(buffer, length);
        inFile.close();
        std::string readStr(buffer, length);
//        readValueBuffer.push_back(readStr);
        return readStr;
    }

    // 从内存或磁盘中读取数据的实现
    std::string read(const int& key) {
        std::shared_lock<std::shared_mutex> lock(rw_mutex);
        //在cache中找
        std::string Data = Cache.get(key);
        if(Data.size() != 0){
            std::cout << "在cache中找" << std::endl;
            return Data;
        }
        //在内存中找
        if (HashMap.find(key) != HashMap.end()) {
            KVNode& node = HashMap[key];
            std::string result;
            if (node.in_memory) {
                std::cout << "在写缓冲区中找" << std::endl;
                result = valueBuffer[node.memory_address];
            } else {
                std::cout << "在磁盘中找" << std::endl;
                result = readFromDisk(node.DiskOffset, node.length);
            }
//            readValueBuffer.push_back(result);
            LRUCacheNode LruNode{key,result};
//            readValueBufferIndex++;
            Cache.put(key,LruNode);
            return result;
        }
        return "value not here";
    }

    void DelValue(int& key){
        auto it = HashMap.find(key);
        if (it != HashMap.end()) {
            HashMap.erase(it); // 删除与 some_key 相关联的元素
        } else{
            std::cout << "key not here" << std::endl;
        }
    }
};

int main() {
    KVStore kvStore(1000, "disk_data.bin",5);
    std::cout << "Testing write operations..." << std::endl;
    for(int i = 0;i< 10000;i++){
        kvStore.write(i,i*15);
    }

    for(int j=0;j<3;j++){
        for(int i =0;i<5;i++){
            kvStore.deserializeValue<int>(kvStore.read(i));
        }
    }

    return 0;
}
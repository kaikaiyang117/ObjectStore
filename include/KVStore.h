//
// Created by kky on 11/30/24.
//

#ifndef GENERICPROTOBUFEXAMPLE_KVSTORE_H
#define GENERICPROTOBUFEXAMPLE_KVSTORE_H

#include <unordered_map>
#include <vector>
#include <string>
#include <ctime>
#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>
#include "serialize.h"
#include "LRUCache.h"
#include <list>
#include <mutex>
#include <bitset>
#include <shared_mutex>
#include <thread>

const size_t BLOCK_SIZE = 64;              // 块大小
const size_t TOTAL_BLOCKS = 1024 * 1024 * 1024 / 64; // 1MB 文件，共 16384 块
const size_t KEY_SIZE = 40;  //存放hashnode的节点大小
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
    std::shared_mutex rw_mutex;//读写锁


public:
    KVStore(size_t buffer_limit, const std::string& disk_filename,int Lru_Capacity);
    ~KVStore();

    void initializeDisk(std::string fileName);
    // 查找空闲块并返回其索引，若无空闲块则返回 -1
    int findFreeBlock();

//    对key序列化
    static std::string serializeKey(const int key);

    //反序列化
    static int  deserializeKey(const std::string& serialDataKey);

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

        HashMap[key] = KVNode(key, -1, 0, valueBuffer.size()-1, true, std::time(nullptr));

        if (keyBuffer.size() >= bufferLimit) {
            flushBuffersToDisk();
        }
        return true;
    }



    // 从内存或磁盘中读取数据的实现
    std::string read(const int& key);

    void flushBuffersToDisk();

    std::string readFromDisk(int blockIndex, size_t length);

    void DelValue(int& key);
};

#endif //GENERICPROTOBUFEXAMPLE_KVSTORE_H

//
// Created by kky on 11/30/24.
//

#include "../include/KVStore.h"


KVStore::KVStore(size_t buffer_limit, const std::string& disk_filename,int Lru_Capacity) : bufferLimit(buffer_limit), disk_filename(disk_filename) ,LruCapacity(Lru_Capacity){
    Cache.setCapacity(LruCapacity);
    initializeDisk(disk_filename);
}

KVStore::~KVStore() {
    if (diskFile.is_open()) {
        flushBuffersToDisk();
        diskFile.close();
    }
}

void KVStore::initializeDisk(std::string fileName) {
    std::ofstream disk(fileName, std::ios::binary | std::ios::app);
    disk.seekp(BLOCK_SIZE * TOTAL_BLOCKS - 1);
    disk.write("", 1);
    disk.close();
}

int KVStore::findFreeBlock() {
    for (size_t i = 0; i < TOTAL_BLOCKS; ++i) {
        if (!block_bitmap.test(i)) {
            return i;
        }
    }
    std::cout << "no free block;" <<std::endl;
    return -1;
}

std::string KVStore::serializeKey(const int key) {
    std::string serialDataKey;
    GenericMessage message = createMessageData(key);
    serialDataKey = serializeMessage(message);
    return serialDataKey;
}
//反序列化
int  KVStore::deserializeKey(const std::string& serialDataKey) {
    int key;
    GenericMessage messageInt = deserializeMessage(serialDataKey);
    key = GetMessageInt(messageInt);
    return key;
}


// 从内存或磁盘中读取数据的实现
std::string KVStore::read(const int& key) {

//    std::shared_lock<std::shared_mutex> lock(rw_mutex);
    std::unique_lock<std::shared_mutex> lock(rw_mutex);
    std::string Data = Cache.get(key);
    if(Data.size() != 0){
//        std::cout << "在cache中找" << std::endl;
        return Data;
    }

    if (HashMap.find(key) != HashMap.end()) {
        KVNode& node = HashMap[key];
        std::string result;
        if (node.in_memory) {
//            std::cout << "在写缓冲区中找" << std::endl;
            result = valueBuffer[node.memory_address];
        } else {
//            std::cout << "在磁盘中找" << std::endl;
            result = readFromDisk(node.BlockIndex, node.length);
        }
        LRUCacheNode LruNode{key,result};
        Cache.put(key,LruNode);
        return result;
    }
    return "";
}

void KVStore::flushBuffersToDisk() {
    diskFile.open(disk_filename, std::ios::binary | std::ios::in | std::ios::out);
    if (!diskFile.is_open()) {
        throw std::runtime_error("无法打开磁盘文件");
    }
    for (size_t i = 0; i < keyBuffer.size(); ++i) {
        const std::string& keyData = keyBuffer[i];
        const std::string& valueData = valueBuffer[i];

        int freeBlockIndex = findFreeBlock();
        if(freeBlockIndex!=-1){
            diskFile.seekp(freeBlockIndex*BLOCK_SIZE);
            // 写入 value 到磁盘
            diskFile.write(valueData.data(), valueData.size());
            block_bitmap.set(freeBlockIndex);  // 标记为已使用

            int key = deserializeKey(keyData);
            HashMap[key].BlockIndex = freeBlockIndex;
            HashMap[key].in_memory = false;
            HashMap[key].length = valueData.size();
//            std::cout << "Flushed key " << key << " to disk at BlockIndex " << HashMap[key].BlockIndex << "  length is " << valueData.size() <<std::endl;
        }else{
            std::cout << "Space is full"  << std::endl;
            return;
        }
    }
    std::cout << "Flushed finished" << std::endl;
//    HashMap.clear();

    diskFile.close();
    keyBuffer.clear();
    valueBuffer.clear();
}

std::string KVStore::readFromDisk(int blockIndex, size_t length) {

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

void KVStore::DelValue(int& key){
    auto it = HashMap.find(key);
    if (it != HashMap.end()) {
        block_bitmap.reset(it->second.BlockIndex);//图节点
        HashMap.erase(it); // 删除与 some_key 相关联的元素
        Cache.remove(key);
    } else {
        std::cout << "key not here" << std::endl;
    }
}
//
// Created by kky on 11/10/24.
//

#ifndef GENERICPROTOBUFEXAMPLE_LRUCACHE_H
#define GENERICPROTOBUFEXAMPLE_LRUCACHE_H

#include <iostream>
#include <list>
#include <unordered_map>
#include <stdexcept>


struct LRUCacheNode{
    int key;
    std::string Data;
};

class LRUCache {
public:
    // 构造函数，指定缓存容量
    void setCapacity(size_t Lru_capacity);

    // 获取缓存中的值，如果存在则返回值并将其移动到链表头部
    std::string get(const int& key);

    // 插入新的键值对，或更新现有键的值
    void put(const int& key, const LRUCacheNode& value);

    // 显示缓存内容（用于调试）
    void display() const;

private:
    size_t capacity;  // 缓存容量
    std::list<std::pair<int, LRUCacheNode>> cacheList;  // 用于存储缓存项的双向链表
    std::unordered_map<int, typename std::list<std::pair<int, LRUCacheNode>>::iterator> cacheMap;  // 用于快速查找的哈希表
};

#endif //GENERICPROTOBUFEXAMPLE_LRUCACHE_H

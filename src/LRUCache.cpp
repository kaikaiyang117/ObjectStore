//
// Created by kky on 11/10/24.
//

#include "../include/LRUCache.h"

void LRUCache::setCapacity(size_t Lru_capacity){
    capacity = Lru_capacity;
}

std::string LRUCache::get(const int& key) {
    auto it = cacheMap.find(key);
    if (it == cacheMap.end()) {
        return "";
    }
    // 将节点移到链表头部以表示它最近被访问
    cacheList.splice(cacheList.begin(), cacheList, it->second);
    return it->second->second.Data;
}

void LRUCache::put(const int& key, const LRUCacheNode& value) {
    auto it = cacheMap.find(key);

    // 如果键已存在，更新其值并将其移动到头部
    if (it != cacheMap.end()) {
        it->second->second = value;
        cacheList.splice(cacheList.begin(), cacheList, it->second);
        return;
    }

    // 如果缓存已满，删除最久未使用的项（链表尾部）
    if (cacheList.size() >= capacity) {
        auto last = cacheList.back();
        cacheMap.erase(last.first);
        cacheList.pop_back();
    }

    // 将新项插入链表头部并添加到哈希表中
    cacheList.emplace_front(key, value);
    cacheMap[key] = cacheList.begin();
}

void LRUCache::display() const {
    for (const auto& pair : cacheList) {
        std::cout << "{" << pair.first << ":" << pair.second.Data << "} ";
    }
    std::cout << std::endl;
}

// 删除缓存中的节点
void LRUCache::remove(int& key) {
    auto it = cacheMap.find(key);  // 查找指定的 key
    if (it != cacheMap.end()) {
        // 找到节点，删除它
        cacheList.erase(it->second);  // 从链表中删除
        cacheMap.erase(it);  // 从哈希表中删除
    } else {

        std::cerr << "Key " << key << " not found in cache." << std::endl;
    }
}

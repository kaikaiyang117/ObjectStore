#include "include/KVStore.h"
#include "include/serialize.h"
#include <mutex>
#include <condition_variable>
#include <unordered_map>
#include <vector>
#include <thread>
#include <iostream>

const int count = 100000;
std::unordered_map<int, std::condition_variable> cv_map;
std::unordered_map<int, std::mutex> mtx_map;
std::unordered_map<int, bool> write_done_map;
//std::unordered_map<int, int> write_counter;

void readerThread(KVStore &kvStore, int id) {
    {
        std::unique_lock<std::mutex> lock(mtx_map[id]);
        cv_map[id].wait(lock, [&] { return write_done_map[id]; });  // 等待写者完成
    }

    for (int i = id * count; i < (id + 1) * count; ++i) {
        std::string value = kvStore.read(i);
        if (value.empty()) {
            std::cout << "Value not found for key " << i << std::endl;
        } else {
//            kvStore.deserializeValue<int>(value);
        }
    }

    std::cout << "Reader " << id << " has finished" << std::endl;
}

void writerThread(KVStore &kvStore, int id) {

    for (int i = id * count; i < (id + 1) * count; ++i) {
        kvStore.write(i, i);
    }

    {
        std::unique_lock<std::mutex> lock(mtx_map[id]);
        write_done_map[id] = true;  // 标记写任务完成
    }

    cv_map[id].notify_one();  // 通知对应的读者
    std::cout << "Writer " << id << " has finished" << std::endl;
}

int main() {
    const int KVStorelimit = 100000;
    const int LruNum = 10000;
    const int readerNum = 20;
    const int writerNum = 20;

    KVStore kvStore(KVStorelimit, "disk_data.txt", LruNum);
    std::vector<std::thread> threads;
    // 初始化条件变量、锁和状态标志
    for (int i = 0; i < writerNum; ++i) {
        mtx_map[i];  // Initialize mutex
        cv_map[i];   // Initialize condition_variable
        write_done_map[i] = false;  // Initialize write status
    }
    // 启动写者线程
    for (int i = 0; i < writerNum; ++i) {
        threads.emplace_back(writerThread, std::ref(kvStore), i);
    }
    // 启动读者线程
    for (int i = 0; i < readerNum; ++i) {
        threads.emplace_back(readerThread, std::ref(kvStore), i);
    }
    for (auto &t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }
    return 0;
}

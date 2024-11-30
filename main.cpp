#include "include/KVStore.h"
#include "include/serialize.h"


void readerThread(KVStore &kvStore, int id) {
    for(int i=id*100;i<(id+1)*100;i++){
        std::string value = kvStore.read(i);
        if(value.length()==0){
            std::cout << "value not here" << std::endl;
        }else{
            kvStore.deserializeValue<int>(value);
        }
    }
}

// 写者线程函数
void writerThread(KVStore &kvStore, int id) {
    for(int i=id*100;i<(id+1)*100;i++){
        kvStore.write(i, i);
        std::cout << "Writer " << id << " wrote key " << i << " with value: " << i << std::endl;
    }
}

//删除者线程
void deleteThread(KVStore &kvStore, int id, int key){
    for(int i=id*100;i<(id+1)*100;i++){
        kvStore.DelValue(i);
        std::cout << "Writer " << id << " wrote key " << i << " with value: " << i << std::endl;
    }
}


int main() {


    const int KVStorelimit = 10000;
    const int LruNum = 1000;
    const int readerNum = 100;
    const int writerNum = 100;
    const int delerNUmber= 100;

    KVStore kvStore(KVStorelimit, "disk_data.txt", LruNum);
    std::vector<std::thread> threads;
    for (int i = 0; i < writerNum; ++i) {
        threads.emplace_back(writerThread, std::ref(kvStore), i);
    }

    // 启动5个读者线程
    for (int i = 0; i < readerNum; ++i) {
        threads.emplace_back(readerThread, std::ref(kvStore), i);
    }

    // 等待所有线程完成
    for (auto &t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }

    return 0;
}
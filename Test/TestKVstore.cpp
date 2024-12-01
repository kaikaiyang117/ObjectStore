#include "../include/KVStore.h"

int main(){
    const int kvNum = 10000;
    KVStore kvStore(10000, "disk_data.txt", 100);
    for(int i=0;i<kvNum;i++){
        kvStore.write(i,i*10);
    }

    for(int i=0;i<5;i++){
        std::string value = kvStore.read(i);
        kvStore.deserializeValue<int>(value);
    }

    for(int i=0;i<5;i++){
        kvStore.DelValue(i);
    }

    for(int i=0;i<5;i++){
        std::string value = kvStore.read(i);
        kvStore.deserializeValue<int>(value);
    }
}
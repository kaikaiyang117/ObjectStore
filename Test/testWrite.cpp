#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>
#include <string>


const size_t BLOCK_SIZE = 64;              // 块大小
const size_t TOTAL_BLOCKS = 1024 * 1024 / 64; // 1MB 文件，共 16384 块
const std::string DISK_FILE = "disk.bin";  // 使用 .bin 后缀文件

// 位视图数组，用于跟踪块的使用情况
std::bitset<TOTAL_BLOCKS> block_bitmap;

// 初始化磁盘文件（如果文件不存在则创建，并填充为零）
void initializeDisk() {
    std::ofstream disk(DISK_FILE, std::ios::binary | std::ios::app);
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

// 写入数据到磁盘，返回写入的块索引，若失败则返回 -1
int writeData(const std::string& data) {
    if (data.size() > BLOCK_SIZE) {
        std::cerr << "Data exceeds block size!\n";
        return -1;
    }

    int freeBlockIndex = findFreeBlock();
    if (freeBlockIndex == -1) {
        std::cerr << "No free blocks available!\n";
        return -1;
    }

    std::ofstream disk(DISK_FILE, std::ios::binary | std::ios::in | std::ios::out);
    disk.seekp(freeBlockIndex * BLOCK_SIZE);
    disk.write(data.c_str(), data.size());
    disk.close();

    block_bitmap.set(freeBlockIndex);  // 标记为已使用
    return freeBlockIndex;
}

// 从磁盘读取指定块的数据
std::string readData(int blockIndex) {
    if (blockIndex < 0 || blockIndex >= TOTAL_BLOCKS || !block_bitmap.test(blockIndex)) {
        std::cerr << "Invalid block index or block is not in use!\n";
        return "";
    }

    std::ifstream disk(DISK_FILE, std::ios::binary);
    disk.seekg(blockIndex * BLOCK_SIZE);

    char buffer[BLOCK_SIZE] = {0};
    disk.read(buffer, BLOCK_SIZE);
    disk.close();

    return std::string(buffer);
}

// 删除指定块的数据
void deleteData(int blockIndex) {
    if (blockIndex < 0 || blockIndex >= TOTAL_BLOCKS || !block_bitmap.test(blockIndex)) {
        std::cerr << "Invalid block index or block is not in use!\n";
        return;
    }

    std::ofstream disk(DISK_FILE, std::ios::binary | std::ios::in | std::ios::out);
    disk.seekp(blockIndex * BLOCK_SIZE);
    char empty[BLOCK_SIZE] = {0};
    disk.write(empty, BLOCK_SIZE);
    disk.close();

    block_bitmap.reset(blockIndex);  // 标记为空闲
}

int main() {
    initializeDisk();

    // 写入数据
    int blockIndex = writeData("Hello, Disk Block!");
    if (blockIndex != -1) {
        std::cout << "Data written to block: " << blockIndex << std::endl;
    }

    // 读取数据
    std::string data = readData(blockIndex);
    std::cout << "Read data from block " << blockIndex << ": " << data << std::endl;

    // 删除数据
    deleteData(blockIndex);
    std::cout << "Data in block " << blockIndex << " deleted." << std::endl;

    return 0;
}

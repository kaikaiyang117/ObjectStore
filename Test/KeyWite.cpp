#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

struct KVNode {
    int key;
    int BlockIndex;
    size_t length;
    long memory_address;
    bool in_memory;
    std::time_t timestamp;

    KVNode(int key, int BlockIndex, size_t length, long memory_address, bool in_memory, std::time_t timestamp)
            : key(key), BlockIndex(BlockIndex), length(length), memory_address(memory_address), in_memory(in_memory), timestamp(timestamp) {}

    KVNode() : key(0), BlockIndex(0), length(0), memory_address(0), in_memory(false), timestamp(0) {}
};

void writeNodesToFile(const std::string &filename, const std::vector<KVNode> &nodes) {
    std::ofstream ofs(filename, std::ios::binary | std::ios::trunc);
    if (!ofs) {
        std::cerr << "Error opening file for writing.\n";
        return;
    }

    std::cout << "大小为:"<< sizeof(KVNode) <<std::endl;

    for (const auto &node : nodes) {
        ofs.write(reinterpret_cast<const char *>(&node), sizeof(KVNode));
    }

    ofs.close();
}

KVNode readNodeFromFile(const std::string &filename, std::streampos index) {
    std::ifstream ifs(filename, std::ios::binary);
    if (!ifs) {
        std::cerr << "Error opening file for reading.\n";
        return KVNode();
    }

    ifs.seekg(index * sizeof(KVNode), std::ios::beg);
    KVNode node;
    ifs.read(reinterpret_cast<char *>(&node), sizeof(KVNode));

    ifs.close();
    return node;
}

int main() {
    std::vector<KVNode> nodes = {
            KVNode(1, 100, 50, 0x123456, true, std::time(nullptr)),
            KVNode(2, 200, 75, 0x654321, false, std::time(nullptr)),
            KVNode(3, 300, 100, 0xabcdef, true, std::time(nullptr))
    };

    std::string filename = "kv_nodes.bin";

    // 写入结构体
    writeNodesToFile(filename, nodes);

    // 读取第2个节点
    KVNode readNode = readNodeFromFile(filename, 1);
    std::cout << "Read Node - Key: " << readNode.key
              << ", BlockIndex: " << readNode.BlockIndex
              << ", Length: " << readNode.length
              << ", Memory Address: " << readNode.memory_address
              << ", In Memory: " << (readNode.in_memory ? "Yes" : "No")
              << ", Timestamp: " << readNode.timestamp << '\n';

    return 0;
}

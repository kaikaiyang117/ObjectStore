#include "../include/LRUCache.h"
#include <iostream>

int main() {
    // Create an LRUCache with a capacity of 3
    LRUCache cache;
    cache.setCapacity(3);

    // Create some cache nodes
    LRUCacheNode node1{100};  // Node with address 100
    LRUCacheNode node2{200};  // Node with address 200
    LRUCacheNode node3{300};  // Node with address 300
    LRUCacheNode node4{400};  // Node with address 400

    // Insert nodes into the cache
    std::cout << "Inserting node1, node2, and node3" << std::endl;
    cache.put(1, node1);
    cache.put(2, node2);
    cache.put(3, node3);

    // Display cache contents
    cache.display(); // Expected: {3:300} {2:200} {1:100}

    // Access node with key 1 (should move it to the front)
    std::cout << "Accessing node with key 1" << std::endl;
    cache.get(1);
    cache.display(); // Expected: {1:100} {3:300} {2:200}

    // Insert node4, which should evict node2 (the least recently used)
    std::cout << "Inserting node4 (causes eviction)" << std::endl;
    cache.put(4, node4);
    cache.display(); // Expected: {4:400} {1:100} {3:300}

    // Try to get a non-existent key to test error handling
    try {
        cache.get(5); // This should throw an exception
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

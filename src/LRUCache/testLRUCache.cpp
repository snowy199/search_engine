#include <iostream>
#include "LRUCache/CacheManager.h"
#include <unistd.h>

int main() {
    CacheManager* pCaches = CacheManager::getInstance();
    LRUCache cache = pCaches->getCache(0);
    std::cout << "key1: " << cache.getValue("key1") << std::endl;
    sleep(5);
    cache.update();
    std::cout << "key1: " << cache.getValue("key1") << std::endl;
    return 0;
}


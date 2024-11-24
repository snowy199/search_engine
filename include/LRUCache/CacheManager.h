/**
 *  * Project C++49期提高
 *   */

#ifndef _CACHEMANAGER_H
#define _CACHEMANAGER_H

#include "LRUCache.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

class CacheManager {
public:
    // 获取 CacheManager 的单例实例
    static CacheManager* getInstance();

    /**
     * 获取指定索引的缓存
     * @param i 索引
     * @return LRUCache 对象的引用
     */
    LRUCache& getCache(int i);

    // 更新缓存
    void updateCache();

    // 获取信息
    string getInfo();

    // 存储数据
    void store();

    // 数据同步
    void dataSyn();

private:
    vector<LRUCache> _caches;  // 缓存向量，存放 LRUCache 对象
    static CacheManager* _pCacheManager;  // CacheManager 单例对象指针

    /**
     * 构造函数
     */
    CacheManager();

};

#endif //_CACHEMANAGER_H


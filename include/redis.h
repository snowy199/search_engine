#ifndef __REDIS__
#define __REDIS__

#include <sw/redis++/redis.h>
#include <nlohmann/json.hpp>
#include <iostream>

using namespace std;

class Redis {
public:
        // 获取 Redis 的单例实例
    static Redis* getInstance(const string& host, const string& port);

    // 设置 Redis 中的键值对数据
    bool setRedisData(const string& key, const string& value);

    // 获取 Redis 中指定键的值
    string getRedisData(const string& key);

    // 设置 Redis 中指定键的过期时间
    bool expireRedisData(const string& key, int seconds);

private:
    // 私有构造函数，接受 Redis 服务器的主机和端口作为参数
    Redis(const string& host, const string& port);

    static Redis* _pInstance;  // Redis 单例对象指针
    sw::redis::Redis _redis;  // Redis 连接对象

};

#endif


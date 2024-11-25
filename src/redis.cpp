#include "redis.h"

Redis *Redis::_pInstance = nullptr;

Redis::Redis(const string &host,const string &port)
: _redis("tcp://127.0.0.1:6379")
{
    string ip = "tcp://" + host + ":" + port;
    _redis = sw::redis::Redis(ip);
}

Redis * Redis::getInstance(const string &host,const string  &port)
{  
    if(_pInstance == nullptr){
        _pInstance = new Redis(host,port);
    }
    return _pInstance;
}

bool Redis::setRedisData(const string &key,const string &value){
    return _redis.set(key,value);
}

string Redis::getRedisData(const string &key){
    auto value = _redis.get(key);
    if(value){
        return value.value();
    }else{
        return string();
    }
}

bool Redis::expireRedisData(const string &key,int seconds){
    return _redis.expire(key,seconds);
}

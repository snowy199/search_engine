/**
 *  * Project Untitled
 *   */

#ifndef _MUTEX_H
#define _MUTEX_H
#include <pthread.h>

#ifndef __THREAD_ERROR_CHECK__
#define __THREAD_ERROR_CHECK__
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 *  * 线程错误检查宏
 *   * @param ret 函数返回值
 *    * @param msg 错误信息
 *     */
inline void THREAD_ERROR_CHECK(int ret, const char* msg) {
    if (ret != 0) {
        fprintf(stderr, "%s: %s\n", msg, strerror(ret));
        exit(1);

    }

}
#endif //__THREAD_ERROR_CHECK__

class Mutex {
public:
    /**
     *      * 构造函数
     *           */
    Mutex();

    /**
     *      * 析构函数
     *           */
    ~Mutex();

    /**
     *      * 加锁
     *           */
    void lock();

    /**
     *      * 解锁
     *           */
    void unlock();

    /**
     *      * 尝试加锁
     *           */
    void trylock();

    /**
     *      * 获取 pthread_mutex_t 结构体指针
     *           * @return pthread_mutex_t 结构体指针
     *                */
    pthread_mutex_t* getMutexPtr();

private:
    pthread_mutex_t _mutex;  // pthread_mutex_t 结构体

};

#endif //_MUTEX_H


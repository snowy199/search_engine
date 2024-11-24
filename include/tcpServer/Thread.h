/**
 *  * Project Untitled
 *   */

#ifndef _THREAD_H
#define _THREAD_H

#include <pthread.h>
#include <functional> 
#include <iostream>

using std::function;
using std::string;

class Thread {
public: 
    using ThreadCallback = function<void(int)>;

    /**
     *      * 构造函数
     *           * @param cb 线程回调函数
     *                * @param tNum 线程编号
     *                     */
    Thread(ThreadCallback&& cb, int tNum);

    /**
     *      * 析构函数
     *           */
    ~Thread(){}

    /**
     *      * 创建线程
     *           */
    void create();

    /**
     *      * 等待线程结束并回收资源
     *           */
    void join();

private: 
    pthread_t _tid;         // 线程ID
    bool _isRunning;        // 线程运行状态
    ThreadCallback _cb;     // 线程回调函数
    int _tNum;              // 线程编号

    /**
     *      * 线程函数
     *           * @param void* 参数指针
     *                */
    static void* threadFunc(void*);

};

#endif //_THREAD_H


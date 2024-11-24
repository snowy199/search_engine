/**
 *  * Project Untitled
 *   */

#ifndef _CONDITION_H
#define _CONDITION_H

#include "Mutex.h"

class Condition {
public:
    /**
     *      * 构造函数
     *           * @param mutex 互斥锁对象的引用
     *                */
    Condition(Mutex& mutex);

    /**
     *      * 析构函数
     *           */
    ~Condition();

    /**
     *      * 等待条件
     *           */
    void wait();

    /**
     *      * 发送信号
     *           */
    void signal();

    /**
     *      * 广播信号
     *           */
    void broadcast();

private:
    Mutex& _mutex;  // 互斥锁对象的引用
    pthread_cond_t _cond;  // 条件变量

};

#endif //_CONDITION_H


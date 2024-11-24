/**
 *  * Project Untitled
 *   */

#ifndef _THREADPOOL_H
#define _THREADPOOL_H

#include "TaskQueue.h"
#include "Thread.h"
#include <vector>
#include <unistd.h>
#include <memory>

using std::vector;

class ThreadPool {
public: 
    using Task = TaskQueue::Elemtype;

    /**
     *      * 构造函数
     *           * @param threadNumber 线程数量
     *                * @param queueSize 任务队列大小
     *                     */
    ThreadPool(size_t threadNumber, size_t queueSize);

    /**
     *      * 添加任务到线程池
     *           * @param task 任务函数
     *                */
    void addTask(Task && task);

    /**
     *      * 启动线程池
     *           */
    void start();

    /**
     *      * 关闭线程池
     *           */
    void shutdown();

private: 
    size_t _threadNumber;                           // 线程数量
    vector<std::unique_ptr<Thread>> _threadPool;     // 线程池
    TaskQueue _taskQueue;                           // 任务队列
    bool _exit;                                     // 线程池退出标志

    /**
     *      * 执行任务
     *           * @param tNum 线程编号
     *                */
    void doTask(int tNum);

};

#endif //_THREADPOOL_H


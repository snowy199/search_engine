#include "tcpServer/ThreadPool.h"

/**
 * ThreadPool implementation
 */


/**
 * @param threadNumber
 * @param queueSize
 */
ThreadPool::ThreadPool(size_t threadNumber, size_t queueSize)
    :_threadNumber(threadNumber)
    ,_taskQueue(queueSize)
     ,_exit(false)
{}

/**
 * @param task
 * @return void
 */
void ThreadPool::addTask(Task && task) {
    if(!_exit && task){
        _taskQueue.push(std::move(task));
    }
    return;
}

/**
 * @return void
 */
void ThreadPool::start() {
    for(size_t i = 0; i < _threadNumber; ++i){
        std::unique_ptr<Thread> upth(new Thread(std::bind(&ThreadPool::doTask, this, std::placeholders::_1), i));
        _threadPool.push_back(std::move(upth));
    }
    for(auto &it : _threadPool){
        it->create();
    }
    return;
}

/**
 * @return void
 */
void ThreadPool::shutdown() {
    _exit = true;
    while(!_taskQueue.isEmpty()){
        sleep(1);
    }

    _taskQueue.wakeUpAll(); 

    for(auto &it : _threadPool){
        it->join();
    }
    return;
}




/**
 * @return void
 */
void ThreadPool::doTask(int tNum) {
    while(!_exit || !_taskQueue.isEmpty()){
        Task task = _taskQueue.pop();
        if(task) task(tNum);
        else break;
    }
    return;
}

#include "tcpServer/TaskQueue.h"

/**
 * TaskQueue implementation
 */


/**
 * @param capacity
 */
TaskQueue::TaskQueue(size_t capacity)
:_capacity(capacity)
,_q()
,_mutex()
,_condP(_mutex)
,_condC(_mutex){
}

/**
 * @return bool
 */
bool TaskQueue::isEmpty() {
    return _q.size() == 0;
}

/**
 * @return bool
 */
bool TaskQueue::isFull() {
    return _q.size() == _capacity;
}

/**
 * @param value
 * @return void
 */
void TaskQueue::push(const Elemtype && value) {
    _mutex.lock();
    if(isFull()){
        _condP.wait();
    }
    _q.push(value);
    _condC.signal();
    _mutex.unlock();
    return;
}

/**
 * @return int
 */
TaskQueue::Elemtype TaskQueue::pop() {
    _mutex.lock();
    while(isEmpty()){
        _condC.wait();
        if(isEmpty()){
            _mutex.unlock();
            return nullptr;
        }
    }
    Elemtype tmp = _q.front();
    _q.pop();
    _condP.signal();
    _mutex.unlock();
    return tmp;
}

void TaskQueue::wakeUpAll(){
    _mutex.lock();
    _condC.broadcast();
    _mutex.unlock();
} 

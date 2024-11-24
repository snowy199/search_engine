/**
 * Project C++49期提高
 */


#include "LRUCache/TimerManager.h"
#include "LRUCache/CacheUpdateTask.h"

/**
 * TimerManager implementation
 */


TimerManager::TimerManager() 
{
    CacheUpdateTask task;
    _thread = new Thread(std::bind(&CacheUpdateTask::pocess, task, std::placeholders::_1), -1);

}

TimerManager::~TimerManager(){
    if(_thread){
        _thread->join();
        delete _thread;
    }
    _thread = nullptr;
}



/**
 * @return void
 */
void TimerManager::start() {
    _thread->create();
    return;
}

#include "tcpServer/Thread.h"
#include "mylog.h"

using Mylog = mylog::Mylogger; 

/**
 * Thread implementation
 */


/**
 * @param cb
 */
Thread::Thread(ThreadCallback && cb, int tNum) 
:_tid(0)
,_isRunning(false)
,_cb(std::move(cb))
,_tNum(tNum){

}

/**
 * @return void
 */
void Thread::create() {
    int ret = pthread_create(&_tid, nullptr, threadFunc, (void*)this);
    if(ret != 0){
        string error = Mylog::getErrorMsg(ret);
        LogError("pthread_create failed: %s", error.c_str());
    }
    _isRunning = true;
    return;
}

/**
 * @return void
 */
void Thread::join() {
    if(!_isRunning) return;

    int ret = pthread_join(_tid, nullptr);
    if(ret != 0){
        string error = Mylog::getErrorMsg(ret);
        LogError("pthread_join failed: %s", error.c_str());
    }
    _isRunning = false;
    return;
}


/**
 * @param void*
 * @return void*
 */
void* Thread::threadFunc(void* arg) {
    Thread* pth = static_cast<Thread*>(arg); 
    if(pth){
        pth->_cb(pth->_tNum);
    }else{
        std::cout << "No process" << std::endl;
    }
    pthread_exit(nullptr);
    return nullptr;
}

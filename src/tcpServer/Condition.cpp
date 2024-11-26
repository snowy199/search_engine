#include "tcpServer/Condition.h"

/**
 * Condition implementation
 */


/**
 * @param mutex
 */
Condition::Condition(Mutex& mutex) 
:_mutex(mutex){
    int ret = pthread_cond_init(&_cond, nullptr);
    THREAD_ERROR_CHECK(ret, "pthread_cond_init");
}

Condition::~Condition() {
    int ret = pthread_cond_destroy(&_cond);
    THREAD_ERROR_CHECK(ret, "pthread_cond_destroy");
}
/**
 * @return void
 */
void Condition::wait() {
    int ret = pthread_cond_wait(&_cond, _mutex.getMutexPtr());
    THREAD_ERROR_CHECK(ret, "pthread_cond_wait");
    return;
}

/**
 * @return void
 */
void Condition::signal() {
    int ret = pthread_cond_signal(&_cond);
    THREAD_ERROR_CHECK(ret, "pthread_cond_signal");
    return;
}

/**
 * @return void
 */
void Condition::broadcast() {
    int ret = pthread_cond_broadcast(&_cond);
    THREAD_ERROR_CHECK(ret, "pthread_cond_broadcast");
    return;
}


/**
 * Project Untitled
 */


#include "tcpServer/Mutex.h"

/**
 * Mutex implementation
 */


Mutex::Mutex() {
    int ret = pthread_mutex_init(&_mutex, nullptr);
    THREAD_ERROR_CHECK(ret, "pthread_mutex_init");
}
Mutex::~Mutex() {
    int ret = pthread_mutex_destroy(&_mutex);
    THREAD_ERROR_CHECK(ret, "pthread_mutex_destroy");
}

/**
 * @return void
 */
void Mutex::lock() {
    int ret = pthread_mutex_lock(&_mutex);
    THREAD_ERROR_CHECK(ret, "pthread_mutex_lock");
    return;
}

/**
 * @return void
 */
void Mutex::unlock() {
    int ret = pthread_mutex_unlock(&_mutex);
    THREAD_ERROR_CHECK(ret, "pthread_mutex_unlock");
    return;
}

/**
 * @return void
 */
void Mutex::trylock() {
    int ret = pthread_mutex_trylock(&_mutex);
    THREAD_ERROR_CHECK(ret, "pthread_mutex_trylock");
    return;
}

/**
 * @return pthread_mutex_t*
 */
pthread_mutex_t* Mutex::getMutexPtr() {
    return &_mutex;
}


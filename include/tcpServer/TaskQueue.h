/**
 * Project Untitled
 */


#ifndef _TASKQUEUE_H
#define _TASKQUEUE_H
#include "Condition.h"
#include <queue>
#include <functional>

using std::function;
using std::queue;

class TaskQueue {
public: 
    using Elemtype = function<void(int)>;
    
/**
 * @param capacity
 */
TaskQueue(size_t capacity);
~TaskQueue(){}
    
bool isEmpty();
    
bool isFull();
    
/**
 * @param value
 */
void push(const Elemtype && value);
    
Elemtype pop();
    
void wakeUpAll();
private: 
    size_t _capacity;
    queue<Elemtype> _q;
    Mutex _mutex;
    Condition _condP;
    Condition _condC;
};

#endif //_TASKQUEUE_H

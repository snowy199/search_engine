/**
 * Project C++49期提高
 */


#ifndef _TIMERMANAGER_H
#define _TIMERMANAGER_H
#include "tcpServer/Thread.h"

class TimerManager {
public: 
    
 TimerManager();
 ~TimerManager();
    
void start();
    
private: 
    Thread* _thread;
};

#endif //_TIMERMANAGER_H

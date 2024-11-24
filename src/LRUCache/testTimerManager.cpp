#include <iostream>
#include "LRUCache/TimerManager.h"
#include "mylog.h"


int main()
{
    mylog::Mylogger::getInstance();
    TimerManager timeManager;
    timeManager.start();
    return 0;
}


/**
 * Project SearchEngine
 */


#ifndef _SEARCHSERVER_H
#define _SEARCHSERVER_H
#include "TcpServer.h"
#include "LRUCache/TimerManager.h"

class Configuration;

class SearchServer {
public: 
    
/**
 * @param conf
 */
SearchServer(Configuration& conf);
    
void start();
    
void stop();
private: 
    Configuration& _conf;
    TcpServer _tcpServer;
    TimerManager _timerManager;    
    
};

#endif //_SEARCHSERVER_H

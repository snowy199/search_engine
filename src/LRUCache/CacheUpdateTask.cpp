/**
 * Project C++49期提高
 */


#include <sys/epoll.h>
#include <unistd.h>
#include <string.h>
#include "LRUCache/CacheUpdateTask.h"
#include "mylog.h"
#include "LRUCache/CacheManager.h"
#include "Configuration.h"

/**
 * CacheUpdateTask implementation
 */

using Mylog = mylog::Mylogger;

Configuration* pConfCacheUpdate = Configuration::getInstance("conf/searchSever.conf");

/**
 * @param i
 */
void CacheUpdateTask::pocess(int i) {
    int timefd = epoll_create1(0);
    if(timefd == -1){
        string error = Mylog::getErrorMsg(errno);
        LogError("Thread %d: epoll_create1 failed: %s", i, error.c_str());
        exit(1);
    }
    
    epoll_event event;
    event.events = EPOLLIN;
    event.data.fd = STDIN_FILENO;

    int ret = epoll_ctl(timefd, EPOLL_CTL_ADD, event.data.fd, &event);
    if(ret == -1){
        string error = Mylog::getErrorMsg(errno);
        LogError("Thread %d: epoll_ctl_add failed: %s", i, error.c_str());
        exit(1);
    }

    epoll_event evtList[1];

    CacheManager* pCaches = CacheManager::getInstance();
    std::map<string,string> confData = pConfCacheUpdate->getConfigMap();
    int synTime = stoi(confData["synTime"]);
    int timing = 0;
    while(1){
        int readyNum = epoll_wait(timefd, evtList, 1, 1000);

        ++timing;
        if(readyNum == -1){
            string error = Mylog::getErrorMsg(errno);
            LogError("Thread %d: epoll_wair error: %s", i, error.c_str());
        }else if(readyNum == 1){
            char buf[256] = {0};
            bzero(buf,sizeof(buf));
            int ret = read(STDIN_FILENO, buf, sizeof(buf));
            if(ret < 0){
                string error = Mylog::getErrorMsg(errno);
                LogError("Thread %d: read error: %s", i, error.c_str());
            }
        }else{
            pCaches->updateCache();
            if(timing >= synTime){
                pCaches->dataSyn();
                timing = 0;
                LogInfo("updateCaches: %s", pCaches->getInfo().c_str());
            }
            
            //LogInfo("updateCaches: %s", pCaches->getInfo().c_str());
        }
    }
}

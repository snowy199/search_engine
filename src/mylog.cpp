#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/PropertyConfigurator.hh>
#include <map>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "mylog.h"
#include "Configuration.h"

using std::map;

namespace mylog{

Mylogger* Mylogger::_pInstance = nullptr;
Category* Mylogger::_plog = nullptr;
pthread_once_t Mylogger::_once = PTHREAD_ONCE_INIT;
string Mylogger::_ctgr;

Configuration* conf = Configuration::getInstance("conf/searchSever.conf");
map<string,string> confInfo = conf->getConfigMap();


Mylogger* Mylogger::getInstance(const string& ctgr){
    _ctgr = ctgr;
    pthread_once(&_once, init);
    return _pInstance;
}
void Mylogger::init(){
    _pInstance = new Mylogger();
    log4cpp::PropertyConfigurator::configure(confInfo["log4cpp.properties"]);
    if(_ctgr == "root"){
        _plog = &Category::getRoot();
    }else{
        _plog = &Category::getRoot().getInstance(_ctgr);
    }
    atexit(destory);
}

void Mylogger::destory(){
    Category::shutdown();
    delete _pInstance;
}

string Mylogger::getErrorMsg(int errorCode){
    char buf[512] = {0};

    return strerror_r(errorCode, buf, sizeof(buf));
}




}//namespace mylog

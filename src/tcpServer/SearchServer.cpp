#include "tcpServer/SearchServer.h"
#include "Configuration.h"
#include "dict/dictionary.h"
#include "webPage/WebPageReader.h"
#include "mylog.h"
#include "LRUCache/CacheManager.h"

/**
 * SearchServer implementation
 */
#include <iostream>
using std::cout;
using std::endl;
/**
 * @param conf
 */
SearchServer::SearchServer(Configuration& conf) 
:_conf(conf)
,_tcpServer(_conf.getConfigMap()["ip"], static_cast<unsigned short>(stoul(_conf.getConfigMap()["port"])),
            static_cast<unsigned int>(stoul(_conf.getConfigMap()["threadNumber"])),
            static_cast<unsigned int>(stoul(_conf.getConfigMap()["queueSize"])))
,_timerManager()
{

    cout << "SearchSever" << endl;
}

/**
 * @return void
 */
void SearchServer::start() {
    map<string,string> confData = _conf.getConfigMap();
    Dictionary* pEnDic = EnDictionary::createInstance();
    pEnDic->readDictAndIndex(confData["en_dict_path"],confData["en_index_path"]);
    Dictionary* pCnDic = CnDictionary::createInstance();
    pCnDic->readDictAndIndex(confData["cn_dict_path"],confData["cn_index_path"]);
    LogInfo("Dictionary Loaded");

    WebPageReader::getInstance(confData["IndexPage.dat"], 
                               confData["OffsetPage.dat"], 
                               confData["WebPage.dat"]);
    LogInfo("WebPages Loaded");


    CacheManager::getInstance();
    LogInfo("CacheManager Loaded");

    _timerManager.start();
    LogInfo("TimerManager start");

    _tcpServer.start();
    LogInfo("SearchSever start");
    return;
}

/**
 * @return void
 */
void SearchServer::stop() {
    _tcpServer.stop();
    return;
}





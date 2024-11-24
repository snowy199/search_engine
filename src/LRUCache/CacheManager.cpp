/**
 * Project C++49期提高
 */


#include "LRUCache/CacheManager.h"
#include "Configuration.h"
#include <map>
#include <unordered_set>

using std::unordered_set;
using std::map;

/**
 * CacheManager implementation
 */
CacheManager* CacheManager::_pCacheManager = nullptr;
Configuration* pConfCache = Configuration::getInstance("conf/searchSever.conf");
/**
 * @return CacheManager*
 */

CacheManager* CacheManager::getInstance() {
    if(_pCacheManager == nullptr){
        _pCacheManager = new CacheManager();
    }
    return _pCacheManager;
}

/**
 * @param i
 * @return LRUCache&
 */
LRUCache& CacheManager::getCache(int i) {
    return _caches[i];
}

/**
 * @return void
 */
void CacheManager::updateCache() {
    for(auto & it : _caches){
        it.update();
    }
    
    return;
}

using std::cout;
using std::endl;

void CacheManager::dataSyn(){
    list<pair<string, pair<string, int>>> totalData(_caches[0].getResultList());
    unordered_set<string> dataSet;
    if(_caches.size() > 1){
        //获取_cache[0]的数据
        for(auto & it : totalData){
            dataSet.insert(it.first);
        }

        cout << "dataSet size" << dataSet.size() << endl;

        for(int i = 1; i < (int)_caches.size(); ++i){
            list<pair<string, pair<string, int>>> & tmpList = _caches[i].getResultList();
            for(auto & it : tmpList){
                if(dataSet.find(it.first) == dataSet.end()){
                    dataSet.insert(it.first);
                    cout << "key: " << it.first << endl;
                    //插到合适位置
                    for(auto curIt = totalData.begin(); curIt != totalData.end(); ++curIt){
                        if(curIt->second.second < it.second.second){
                            totalData.insert(curIt, it);
                        }
                    }
                }
            }
        }
    }



    for(auto & it : _caches){
        it.dataSyn(totalData);
    }

    store();
}

void CacheManager::store(){
    map<string,string> confData = pConfCache->getConfigMap();
    _caches[0].writeToFile(confData["LRUCacheFile"]);
}

string CacheManager::getInfo(){
    std::ostringstream oss;
    for(int i = 0; i < (int)_caches.size(); ++i){
        oss << "Cache " << i <<": " 
            << _caches[i].getSize() << (_caches[i].getSize() > 1 ? " results" : " result")
            << std::endl;
    }
    return oss.str();
}

/**
 * @param filepath
 */
CacheManager::CacheManager() {
    map<string,string> confData = pConfCache->getConfigMap();
    int threadNum = stoi(confData["threadNumber"]);
    for(int i = 0; i < threadNum; ++i){
        _caches.push_back(LRUCache(stoi(confData["LRUCacheCapacity"])));

        _caches[i].initFromFile(confData["LRUCacheFile"]);
    }
}

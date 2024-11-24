/**
 * Project C++49期提高
 */


#include "LRUCache/LRUCache.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <time.h>
#include "Configuration.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::map;
/**
 * LRUCache implementation
 */
Configuration* pConfLRUCache = Configuration::getInstance("conf/searchSever.conf");


/**
 * @param capacity
 */
LRUCache::LRUCache(int capacity) 
    :_resultList()
    ,_hashMap()
    ,_pendingUpdateList()
     ,_capacity(capacity)
     ,_isUpdating(false){

     }


LRUCache::~LRUCache() {

}

/**
 * @param filepath
 */
void LRUCache::initFromFile(const string & filepath) {
    ifstream ifs(filepath);
    if(!ifs.good()){
        cout << "file open failed:"<<filepath << endl;
    }

    int curTime = time(nullptr);
    string line;
    while(getline(ifs, line)){
        istringstream iss(line);       
        if(!iss.good()){
            cout << "istringstream open failed" << endl;
        }

        string key;
        iss >> key;

        string value;
        iss >> value;

        _resultList.push_front(make_pair(key,make_pair(value, curTime)));
        _hashMap.insert(make_pair(key, _resultList.begin()));
    }

    ifs.close();
}

string LRUCache::getValue(const string& key){
    if(_hashMap.find(key) != _hashMap.end()){
        //将最新使用的元素移动到链表头
        auto it = _hashMap[key];
        _resultList.splice(_resultList.begin(), _resultList, it);

        //更新元素最新使用时间
        int curtime = time(nullptr);
        it->second.second = curtime;
        return _hashMap[key]->second.first;
    }else{
        return "";
    }
}
/**
 * @param key
 * @param value
 */
void LRUCache::addElement(const string& key, const string& value) {
    if(_isUpdating){
        cout << "Cache is updating, you can't write now" << endl;
    }else{
        int curtime = time(nullptr);
        if(_hashMap.find(key) != _hashMap.end()){
            auto it = _hashMap[key];
            //如果key已存在，更新值
            it->second.first = value;
            //将最新使用的元素移动到链表头
            _resultList.splice(_resultList.begin(), _resultList, it);

            //更新元素最新使用时间
            it->second.second = curtime;
        }else{
            // cout << "insert Cache :"<<key<<" : "<<value << endl;
            _resultList.push_front(make_pair(key, make_pair(value, curtime)));
            _hashMap.insert(make_pair(key, _resultList.begin()));
        }
    }
}

list<pair<string, pair<string, int>>> LRUCache::getPendingUpdateList(){
    map<string,string> confData = pConfLRUCache->getConfigMap();
    //获取数据前清空链表
    _pendingUpdateList.clear();
    int maxTime = stoi(confData["TimeOut"]);//当某个数据超过maxTime没有被命中则可以舍去;
    int curtime = time(nullptr);

    for(auto it = _resultList.begin(); it != _resultList.end(); ++it){
        if(curtime - it->second.second < maxTime){
            _pendingUpdateList.push_back(*it);
        }else{
            break;
        }
    }
    return std::move(_pendingUpdateList);
}

int LRUCache::getSize(){
    return _resultList.size();
}
/**
 * @return void
 */
void LRUCache::update() {
    _isUpdating = true;
    
    //获取待更新数据
    list<pair<string, pair<string, int>>> tmpResultList = getPendingUpdateList();
    unordered_map<string, list<pair<string, pair<string, int>>> ::iterator>tmpMap;
    
    //将待更新数据存入临时变量
    for(auto it = tmpResultList.begin(); it != tmpResultList.end(); ++it){
        tmpMap.insert(make_pair(it->first, it));
    }

    //将临时变量转移到数据成员
    _hashMap = std::move(tmpMap);
    _resultList = std::move(tmpResultList);

    _isUpdating = false;
    return;
}

void LRUCache::dataSyn(list<pair<string, pair<string, int>>> & totalData){
    _isUpdating = true;
    list<pair<string, pair<string, int>>> tmpResultList;
    unordered_map<string, list<pair<string, pair<string, int>>> ::iterator>tmpMap;

    for(auto it = totalData.begin(); it != totalData.end(); ++it){
        if(tmpMap.find(it->first) == tmpMap.end()){
            tmpResultList.push_front(*it);
            tmpMap.insert(make_pair(it->first, tmpResultList.begin()));
        }
    } 

    _hashMap = std::move(tmpMap);
    _resultList = std::move(tmpResultList);


    _isUpdating = false;
}

list<pair<string, pair<string, int>>> & LRUCache::getResultList(){
    return _resultList;
}

/**
 * @return void
 */
void LRUCache::writeToFile(const string & filepath) {
    ofstream ofs(filepath);
    for(auto it : _resultList){
        ofs << it.first << " " << it.second.first << endl;
    }
    ofs.close();
    return;
}

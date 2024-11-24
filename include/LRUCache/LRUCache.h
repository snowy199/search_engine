/**
 * Project C++49期提高
 */


#ifndef _LRUCACHE_H
#define _LRUCACHE_H
#include <unordered_map>
#include <string>
#include <list>


using std::unordered_map;
using std::string;
using std::list;
using std::pair;

class LRUCache {
public: 
    
/**
 * @param capacity
 */
LRUCache(int capacity = 5000);
    
~LRUCache();
    
/**
 * @param filepath 从filepath路径读取本地缓存库
 */
void initFromFile(const string & filepath);
    
/**
 * @param key
 * @param value
 */
void addElement(const string& key, const string& value);

string getValue(const string& key);

int getSize(); 
    
void update();

void dataSyn(list<pair<string, pair<string, int>>> & totalData);

list<pair<string, pair<string, int>>> & getResultList();
    
void writeToFile(const string & filepath);
private: 
    //list<key, <value, lastusetime>>
    list<pair<string, pair<string, int>>> _resultList;
    unordered_map<string, list<pair<string, pair<string, int>>>::iterator> _hashMap;
    list<pair<string, pair<string, int>>> _pendingUpdateList;
    int _capacity;
    bool _isUpdating;

//获取更新后仍然保留在结果中的缓存
list<pair<string, pair<string, int>>> getPendingUpdateList();

};

#endif //_LRUCACHE_H

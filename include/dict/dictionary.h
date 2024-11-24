#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <vector>
#include<set>
#include<string>
#include<map>
using namespace std;

class Dictionary{
public:
    Dictionary():_isInited(false) {}
    // 读取字典文件和索引文件，构建字典库和索引库
    void readDictAndIndex(const string& dict_path, const string& index_path);

    // 获取字典库
    vector<pair<string, int>> getDict();

    // 获取索引库
    map<string, set<int>> getIndexTable();
private:
    vector<pair<string, int>> _dict;  // 存放字典库
    map<string, set<int>> _index_table;  // 存放索引库
    bool _isInited;
};

class EnDictionary : public Dictionary {
public:
    // 创建英文字典的单例实例
    static Dictionary* createInstance();

private:
    static EnDictionary* _pInstance1;

};

class CnDictionary : public Dictionary {
public:
    // 创建中文字典的单例实例
    static Dictionary* createInstance();

private:
    static CnDictionary* _pInstance2;

};

#endif
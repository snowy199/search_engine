#ifndef _WEBPAGEREADER_H
#define _WEBPAGEREADER_H
#include "pageLib/RssItem.h"
#include <cstring>
#include <dirent.h>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class WebPageReader {
public:
    // 获取单例对象的静态方法，参数分别是倒排索引路径、偏移路径和web路径
    static WebPageReader* getInstance(const string& indexPath, const string& offsetPath, const string& webPath);
    

    // 获取倒排索引库
    const map<string, multimap<double, int>>& getInvertIndexLib() const;

    // 获取偏移库
    const map<int, pair<int, int>>& getOffsetLib() const;

    // 获取web库
    const map<int, RssItem>& getWebLib() const;

    // 获取id_word_weight映射
    const map<int, vector<pair<string, double>>>& getIdWordWeight() const;

private:
    // 倒排索引库，键是单词，值是一个映射: 映射的键是文档ID，值是单词权重
    map<string, multimap<double, int>>
        _invert_index_lib;

    // 偏移库，键是文档ID，值是一个映射，映射的键和值分别是文档在网页库中的起始和长度
    map<int, pair<int, int>> _offset_lib;

    // 网页库，键是文档ID，值是文档内容
    map<int, RssItem> _web_lib;

    // ID-单词-权重映射，键是文档ID，值是一组键值对，键值对的键是单词，值是单词权重
    map<int, vector<pair<string, double>>> _id_word_weight;
    
    // 构造函数是私有的，因为是单例类
    WebPageReader(const string& indexPath, const string& offsetPath, const string& webPath);

    RssItem getRssItem(string data);

    // 单例对象的指针
    static WebPageReader* _instance;
};

#endif

#include "webPage/WebPageReader.h"
#include "mylog.h"
#include "pageLib/RssItem.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <regex>
#include <sstream>
#include <string>
using std::cout;
using std::endl;
using std::ifstream;
using std::map;
using std::ostringstream;
using std::string;
using std::stringstream;

// 初始化静态成员变量
WebPageReader* WebPageReader::_instance = nullptr;

// 静态方法，获取单例对象。如果对象还未被创建，就创建新的对象
WebPageReader* WebPageReader::getInstance(const string& indexPath, const string& offsetPath, const string& webPath) {
    try {
        if(_instance == nullptr){
            _instance = new WebPageReader(indexPath, offsetPath, webPath);
            LogInfo("In WebPageReader::getInstance, indexPath=%s, offsetPath=%s, webPath=%s", indexPath.c_str(), offsetPath.c_str(), webPath.c_str());
        } 
    }catch(const std::bad_alloc& e) {
        LogError("Failed to create WebPageReader instance. Error: %s", e.what());
    }
    return _instance;
}

// 私有构造函数。根据输入的倒排索引路径，偏移路径和web路径，读取文件并填充数据结构
WebPageReader::WebPageReader(const string& indexPath, const string& offsetPath, const string& webPath) {
    // 读取倒排索引文件
    ifstream indexFile(indexPath);
    if(!indexFile.is_open()) {
        LogError("Failed to open index file: %s", indexPath.c_str());
        return;
    }
    string line;
    // 按行读取文件
    while(getline(indexFile, line)) {
        istringstream iss(line);
        string word;
        // 每行第一个字符串是关键词
        iss >> word;
        int docId;
        double weight;
        // 关键词后面是文档ID和权重的对
        while(iss >> docId >> weight) {
            // _invert_index_lib[word][docId] = weight;
            _invert_index_lib[word].insert({ weight, docId });
        }
    }
    indexFile.close();

    // 读取偏移文件
    ifstream offsetFile(offsetPath);
    if(!offsetFile.is_open()) {
        LogError("Failed to open offset file: %s", offsetPath.c_str());
        return;
    }
    while(getline(offsetFile, line)) {
        istringstream iss(line);
        int docId, start, length;
        // 每行是文档ID，起始位置和长度的三元组
        iss >> docId >> start >> length;
        _offset_lib[docId] = make_pair(start, length);
    }
    offsetFile.close();

    // 读取web文件
    ifstream webFile(webPath);
    if(!webPath.c_str()) {
        LogError("Failed to open webPath file: %s", webPath.c_str());
        return;
    }
    // 根据偏移文件，获取每篇文档的内容
    for(const auto& offsetPair : _offset_lib) {
        webFile.seekg(offsetPair.second.first);
        char* buffer = new char[offsetPair.second.second + 1];
        webFile.read(buffer, offsetPair.second.second);
        buffer[offsetPair.second.second] = '\0';
        // 把buffer传给方法
        _web_lib[offsetPair.first] = getRssItem(string(buffer));
        delete[] buffer;
    }

    webFile.close();
    // _invert_index_lib : 单词 （权重，docID) （权重，docID) ...
    // 生成id_word_weight : docID  (单词, 权重)，(单词, 权重) ...
    // 对于每个关键词，获取它在每篇文档中的权重
    for(const auto& indexPair : _invert_index_lib) {
        for(const auto& weightPair : indexPair.second) {
            // weightPair.first为权重 weightPair.second 为docID
            _id_word_weight[weightPair.second].push_back(make_pair(indexPair.first, weightPair.first));
        }
    }
}

// 获取倒排索引库
const map<string, multimap<double, int>>& WebPageReader::getInvertIndexLib() const {
    return _invert_index_lib;
}

RssItem WebPageReader::getRssItem(string data) {
    // 用于匹配XML标签的正则表达式
    std::regex r("<(docid|link|title)>([\\s\\S]*?)</\\1>", std::regex::ECMAScript);

    // 创建一个 std::smatch 对象来保存匹配结果
    std::smatch m;
    RssItem rss;
    // 对输入的XML字符串进行匹配
    while(std::regex_search(data, m, r)) {
        // m[1] 是标签名，m[2] 是标签中的内容
        if(m[1] == "title") {
            rss.title = m[2];
        } else if(m[1] == "link") {
            rss.link = m[2];
        }
        // 从输入的XML字符串中删除已匹配的部分
        data = m.suffix().str();
    }
    std::size_t start = data.find("<content>");
    std::size_t end = data.find("</content>");
    // 移动到 <content> 标签结束的位置
    start += std::string("<content>").length();
    rss.content = data.substr(start, end - start);
    return rss;
}

// 获取偏移库
const map<int, pair<int, int>> &WebPageReader::getOffsetLib() const {
    return _offset_lib;
}

// 获取web库
const map<int, RssItem>& WebPageReader::getWebLib() const {
    return _web_lib;
}

// 获取id_word_weight映射
const map<int, vector<pair<string, double>>>& WebPageReader::getIdWordWeight() const {
    return _id_word_weight;
}

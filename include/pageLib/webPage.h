#ifndef _WEBPAGE_H
#define _WEBPAGE_H
#include <string>
#include <map>
#include <vector>
#include <unordered_map>
#include "simHash.h"
#include "dict/split_tool.h"
#include "dirScanner.h"
#include "pageLib/RssItem.h"


using std::map;
using std::string;
using std::vector;
using std::unordered_map;

class Configuration;
// #ifndef _RSSITEM_H
// #define _RSSITEM_H

// class RssItem {
// public:
//     string title;
//     string link;
//     string description;
//     string content;
// };

// #endif //_RSSITEM_H

class WebPages {
public: 
    using Frequency = unordered_map<string, int>;   

    WebPages(Configuration& conf);
    ~WebPages();
    void creat();
    string getPage(int i);
    size_t getSize(); 
    void store();
    map<int, map<string,double>> getTfidf();

private: 
    Configuration& _conf;
    DirScanner _dirScanner;
    vector<RssItem> _pages;
    vector<Frequency> _termFrequency;//vector for webPage's word frequency 
    Frequency _docFrequency;//包含某word的page的数量
    map<int, map<string, double>> _idf;
    SimHash _simHash;
    SplitTool* _splictTool; 

    void addPage(const string& filename);   
    string dealHTML(const string & s);

    void calculateTfidf();
    void removeDuplicate();

    void addTermFrequency(const string & str);
    void addDocFrequency();
};
#endif
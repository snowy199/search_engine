#include <iostream>
#include <fstream>
#include <sstream>        
// #include "tinyxml2.h"
#include "tinyxml2.h"
#include <regex>
#include <string.h>
#include <cmath>
#include "pageLib/webPage.h"
#include "Configuration.h"
#include "mylog.h"
#include "dict/split_tool.h"

using std::cout;
using std::endl;
using std::ostringstream;
using std::fstream;
using Mylog = mylog::Mylogger;


WebPages::WebPages(Configuration& conf)
:_conf(conf)
,_dirScanner(DirScanner(_conf))
{
    map<string, string> paths = _conf.getConfigMap();
    _splictTool = new CnSplitTool(paths["jieba.dict.utf8"].c_str(), 
                                  paths["hmm_model.utf8"].c_str(), 
                                  paths["user.dict.utf8"].c_str(),
                                  paths["idf.utf8"].c_str(), 
                                  paths["stop_words.utf8"].c_str());
    //cout << "WebPages" << endl;
}

WebPages::~WebPages() {

}

size_t WebPages::getSize(){
    return _pages.size();
}


void WebPages::creat() {
    vector<string> filelist = _dirScanner.getFilelist();
    size_t size = filelist.size();
    LogInfo("Loading %ld .xml files", size);
    for(size_t i = 0; i < size; ++i){
        LogInfo("addPage %d", i+1);
        addPage(filelist[i]);
    }
    LogInfo("%ld .xml files is loaded", size);

    //计算权重
    calculateTfidf();
    
    LogInfo("%ld webPages before rmDuplicate", _pages.size());
    //删除重复网页
    removeDuplicate();
    LogInfo("%ld webPages after rmDuplicate", _pages.size());

    //重新计算权重
    calculateTfidf();
//
    return;
}

string WebPages::getPage(int i) {
    if(i>(int)_pages.size() || i < 0) {
        cout << "out of range" << endl;
        return "";
    }
    ostringstream oss;
    oss << "<doc>"
        << "<docid>" << i+1 << "</docid>"
        << "<title>" << _pages[i].title << "</title>"
        << "<link>" << _pages[i].link << "</link>"
        << "<description>" << _pages[i].description << "</description>"
        << "<content>" << _pages[i].content << "</content>"
        << "</doc>";
    return oss.str();
}

void WebPages::store() {
    std::ofstream ofs((_conf.getConfigMap())["WebPage.dat"]);
    if(!ofs.good()){
        string error = Mylog::getErrorMsg(errno); 
        LogError("WebPage ofs open failed: %s", error.c_str());
    }
    int size = _pages.size();
    //cout << size << endl;
    for(int i = 0; i < size; ++i){
        ofs << getPage(i);
    }
    return;
}

map<int, map<string,double>> WebPages::getTfidf() {
    return _idf;
}


using namespace tinyxml2;
void WebPages::addPage(const string& filepath) {
    XMLDocument doc;
    XMLError result = doc.LoadFile(filepath.c_str());
    if(result == XML_SUCCESS){
        XMLElement* root = doc.RootElement();
        if(root){
            XMLElement * channel = root->FirstChildElement("channel");
            while(channel){
                XMLElement* title = channel->FirstChildElement("title");
                XMLElement* link = channel->FirstChildElement("link");
                XMLElement* description = channel->FirstChildElement("description");
                if(description == nullptr) {
                    channel = channel->NextSiblingElement("channel");
                    continue;
                }

                XMLElement* item = description->NextSiblingElement();
                
                //cout << "while(item)" << endl;
                while(item){
                    if(strcmp(item->Name(), "item") == 0){
                        XMLElement* item_title = item->FirstChildElement("title");
                        XMLElement* item_link = item->FirstChildElement("link");
                        XMLElement* item_description = item->FirstChildElement("description");
                        if(item_description == nullptr){
                            item = item->NextSiblingElement();
                            continue;
                        }

                        //cout << _pages[_pages.size()-1].title << endl;

                        XMLElement* content = item_description->NextSiblingElement();

                        while(content){
                            //cout << content->Name() << endl;;
                            if(strncmp(content->Name(), "content", strlen("content"))==0){
                                if(content->GetText()!=nullptr){
                                    _pages.push_back({item_title->GetText(),
                                                      item_link->GetText(),
                                                      dealHTML(description->GetText()),
                                                      dealHTML(content->GetText())});

                                    addTermFrequency(_pages.back().content);
                                }

                            }
                            content = content->NextSiblingElement();
                        }

                    }else if(strncmp(item->Name(), "content", strlen("content"))==0){
                        if(item->GetText()!=nullptr){
                            _pages.push_back({title->GetText(),
                                             link->GetText(),
                                             dealHTML(description->GetText()),
                                             dealHTML(item->GetText())});
                            
                            //cout << "addFrequency" << endl;
                            addTermFrequency(_pages.back().content);
                        }
                    }


                    item = item->NextSiblingElement();
                }




                channel = channel->NextSiblingElement("channel");
            }
        }else{
            LogError("RootElement failed");

            exit(1);
        }
    }else{
        LogError("LoadFile failed");
        exit(1);
    }

    //cout << _pages.size() << endl;
}

string WebPages::dealHTML(const string & s) {
    string patternstr = string("<p>") + "|" + "</p>" + "|"
                   + "<strong>" + "|" + "</strong>" + "|"
                   + "<em>" + "|" + "</em>" + "|"
                   + "<b>" + "|" + "</b>" + "|"
                   + "<i>" + "|" + "</i>" + "|"
                   + "<a>" + "|" + "</a>" + "|"
                   + "<img>" + "|" + "</img>" + "|"
                   + "<ul>" + "|" + "</ul>" + "|"
                   + "<ol>" + "|" + "</ol>" + "|"
                   + "<li>" + "|" + "</li>" + "|"
                   + "<table>" + "|" + "</table>" + "|"
                   + "<tr>" + "|" + "</tr>" + "|"
                   + "<code>" + "|" + "</code>" + "|"
                   + "<pre>" + "|" + "</pre>" + "|" 
                   + "<h\\d+>" + "|" + "</h\\d+>" + "|"
                   + "<span.*?>" + "|" + "</span>" + "|"
                   + "<a.*?>" + "|" 
                   + "<div.*?>" + "|" + "</div>" + "|"
                   + "<p.*?>" + "|" + "<pre.*?>" + "|"
                   + "<h1.*?>" + "|" + "<h2.*?>" + "|" + "<h3.*?>" + "|"
                   + "<section.*?>" + "|"
                   + "<img.*?>" + "|"
                   + "<br />" + "|"
                   + "<ul.*?>" + "|"
                   + "<li.*?>" + "|"
                   + "<tbody>" + "|" + "</tbody>" + "|"
                   + "<td.*?>" + "|"
                   + "</audio>" + "|"
                   + "<td>" + "|" + "</td>";
    std::regex pattern(patternstr);
    string result = std::regex_replace(s, pattern, "");
    return result;
}

void WebPages::addTermFrequency(const string & str){
    //cut content using splict_tool
    vector<string> tmpvec = _splictTool->cut(str);
    tmpvec = _splictTool->removeStopWords(tmpvec);

    //create word-frekuency map for this webPage
    unordered_map<string, int> tmpmap;
    for(auto & it : tmpvec){
        if(tmpmap.find(it)==tmpmap.end()){
            tmpmap[it] = 1;
        }else{
            ++tmpmap[it];
        }
    }
    _termFrequency.push_back(std::move(tmpmap));
}


void WebPages::addDocFrequency(){
    //clear _docFrequency for recalculate it after remove duplicate
    _docFrequency.clear();
    for(auto itTerm : _termFrequency){
        for(auto wordFrequency : itTerm){
            if(_docFrequency.find(wordFrequency.first) == _docFrequency.end()){
                _docFrequency[wordFrequency.first] = 1;
            }else{
                ++_docFrequency[wordFrequency.first];
            }
        }
    }
}

void WebPages::calculateTfidf(){
    //calculate _docFrequency
    addDocFrequency();
    //clear _idf for recalculate it after remove duplicate
    _idf.clear();

    int size = _pages.size();
    for(int i = 0; i < size; ++i){
        int id = i+1;
        map<string, double> tmp;
        tmp.clear();

        //IDF = log2(N/(DF+1))，
        for(auto it : _termFrequency[i]){
            long tf = it.second;
            long df = 0;
            if(_docFrequency.find(it.first)!=_docFrequency.end()){
                df = _docFrequency[it.first];
            }
            double idf = log2((double)size/(df+1)); 
            double w = tf * idf;
            tmp.insert({it.first, w});
        }

        //归一化
        //w' = w /sqrt(w1^2 + w2^2 +...+ wn^2)
        double norm = 0;
        for(auto & it : tmp){
            norm += pow(it.second, 2);
        }     
        norm = sqrt(norm);
        for(auto & it : tmp){
            it.second = it.second/norm;
        }

        _idf.insert({id, std::move(tmp)});
    }

}

void WebPages::removeDuplicate(){
    size_t i = 0;
    int id = 1;
    while(i < _pages.size()){
        string simhash = _simHash.calculateSimHash(_idf[id]);
        if(_simHash.isDuplicate(simhash)){
            _pages.erase(_pages.begin()+i);
            _termFrequency.erase(_termFrequency.begin()+i);
            ++id;
            continue;
        }
        ++id;
        ++i;
    }
}

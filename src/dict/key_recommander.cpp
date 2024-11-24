#include "dict/key_recommander.h"
#include "dict/dictionary.h"
#include "Configuration.h"
#include "LRUCache/CacheManager.h"
#include "mylog.h"
#include "nlohmann/json.hpp"
#include<iostream>
#include<map>
#include<set>
#include<string>
#include<vector>
using namespace std;



const string conf_path = "conf/searchSever.conf";
Configuration * conf = Configuration::getInstance(conf_path);

CandidateResult::CandidateResult(const string &wordCandidate,int freq,int dist)
    : _wordCandidate(wordCandidate)
    , _freq(freq)
      , _dist(dist)
{

}

bool operator<(const CandidateResult &lhs,const CandidateResult &rhs){
    if(lhs._dist != rhs._dist){
        return lhs._dist < rhs._dist;//1.最短距离小的 相关性高
    }else if(lhs._freq != rhs._freq){
        return lhs._freq > rhs._freq;//2.词频高的 相关性高
    }else{
        return lhs._wordCandidate < rhs._wordCandidate;//3.编码位置靠前的 相关性高
    }
}


KeyRecommander::KeyRecommander(const string &word)
    : _wordBeQuery(word)
{  }


string KeyRecommander::query(int tNum){
    cout << "Be query word: " << _wordBeQuery << endl;
    CacheManager* pCache = CacheManager::getInstance();
    /*从缓存中查找*/
    LRUCache& cache = pCache->getCache(tNum);
    string result =  cache.getValue(_wordBeQuery);
    if(result != string()){
        //cout << "------从缓存中查询-----" << endl;
        LogInfo("Search from LRUCache %s",_wordBeQuery.c_str());
        return result;
    }else{
        /*从词库查找*/
        vector<string> words = doQuery();
        if(words.size()==0){
            nlohmann::json resError = {{"messageId","-1"},{"message","NO KEY WORDS"}};
            LogInfo("Search from dict %s",_wordBeQuery.c_str());
            cache.addElement(_wordBeQuery, resError.dump());
            return resError.dump();
        }

        nlohmann::json res = {{"messageId","100"},{"keywords",{}}};
        for(auto &word : words){
            res["keywords"].push_back(word);
        }

        cache.addElement(_wordBeQuery, res.dump());
        //cout << "------从词库中查询-----" << endl;
        pCache->store();
        LogInfo("Search from dict %s",_wordBeQuery.c_str());
        return res.dump();//dump()函数将JSON对象序列化为字符串形式
    }

}

/* 1.求取一个字符占据的字节数 */
size_t nBytesCode(const char ch);
/* 2.求取一个字符串的字符长度 */
size_t length(const string &str);
/* 3.中英文通用的最小编辑距离算法 */
int editDistance(const string &lhs,const string &rhs);

EnKeyRecommander::EnKeyRecommander(const string &word)
    : KeyRecommander(word)
{  }


vector<string> EnKeyRecommander::doQuery(){
    vector<string> res;

    //获取英文词典，并初始化获得词典库和索引库
    Dictionary *dict = EnDictionary::createInstance();
    dict->readDictAndIndex(conf->_configMap["en_dict_path"],conf->_configMap["en_index_path"]);

    vector<pair<string,int>> dict_vec = dict->getDict();
    map<string,set<int>> dict_map = dict->getIndexTable(); 

    //获取候选词
    set<int> candidate_set;

    //遍历每个字母，将包含该字母的词加入候选集
    for(char &c : _wordBeQuery){
        set<int> s = dict_map[string(1,c)];
        candidate_set.insert(s.begin(),s.end());
    }
    //cout << "candidate_set size = " << candidate_set.size() << endl;

    //从候选词中取出对应词并加入优先队列
    for(auto idx : candidate_set){
        if(_prique.size() < 5){
            _prique.push(CandidateResult(dict_vec[idx].first,dict_vec[idx].second,
                                         editDistance(_wordBeQuery,dict_vec[idx].first)));
        }else{
            CandidateResult cr(dict_vec[idx].first,dict_vec[idx].second,
                               editDistance(_wordBeQuery,dict_vec[idx].first));
            if(cr < _prique.top()){
                _prique.pop();
                _prique.push(CandidateResult(dict_vec[idx].first,dict_vec[idx].second,
                                             editDistance(_wordBeQuery,dict_vec[idx].first)));
            }
        }
    }

    //将优先队列中的词放入结果vector中
    while(!_prique.empty()){
        res.push_back(_prique.top()._wordCandidate);
        _prique.pop();
    }

    //反转vector使相关性高的词排在前面
    reverse(res.begin(),res.end());//注意：C++中的优先级队列 默认是大顶堆实现的
    return res;
}


CnKeyRecommander::CnKeyRecommander(const string &word)
    : KeyRecommander(word)
{  }

vector<string> CnKeyRecommander::doQuery(){
    vector<string> res;

    Dictionary *dict = CnDictionary::createInstance();
    dict->readDictAndIndex(conf->_configMap["cn_dict_path"], conf->_configMap["cn_index_path"]);

    vector<pair<string, int>> dict_vec = dict->getDict();
    map<string, set<int>> dict_map = dict->getIndexTable();

    set<int> candidate_set;

    int i = 0;
    while (i < _wordBeQuery.size()) {
        std::string ch;
        if ((_wordBeQuery[i] & 0xfc) == 0xfc) {
            // 6字节的字
            ch = _wordBeQuery.substr(i, 6);
            i += 6;
        } else if ((_wordBeQuery[i] & 0xf8) == 0xf8) {
            // 5字节的字
            ch = _wordBeQuery.substr(i, 5);
            i += 5;
        } else if ((_wordBeQuery[i] & 0xf0) == 0xf0) {
            // 4字节的字
            ch = _wordBeQuery.substr(i, 4);
            i += 4;
        } else if ((_wordBeQuery[i] & 0xe0) == 0xe0) {
            // 3字节的字
            ch = _wordBeQuery.substr(i, 3);
            i += 3;
        } else if ((_wordBeQuery[i] & 0xc0) == 0xc0) {
            // 2字节的字
            ch = _wordBeQuery.substr(i, 2);
            i += 2;
        } else {
            ++i;
            continue;
        }

        //cout << ch << endl;
        set<int> s = dict_map[ch];
        candidate_set.insert(s.begin(), s.end());
    }

    //cout << "candidate_set.size = " << candidate_set.size() << endl;

    for (auto idx : candidate_set) {
        if (_prique.size() < 5) {
            _prique.push(CandidateResult(dict_vec[idx].first, dict_vec[idx].second,
                                         editDistance(_wordBeQuery, dict_vec[idx].first)));
        } else {
            CandidateResult cr(dict_vec[idx].first, dict_vec[idx].second,
                               editDistance(_wordBeQuery, dict_vec[idx].first));
            if (cr < _prique.top()) {
                _prique.pop();
                _prique.push(
                             CandidateResult(dict_vec[idx].first, dict_vec[idx].second,
                                             editDistance(_wordBeQuery, dict_vec[idx].first)));
            }
        }
    }

    while (!_prique.empty()) {
        res.push_back(_prique.top()._wordCandidate);
        _prique.pop();
    }

    reverse(res.begin(), res.end());

    return res;
}

/*********************************************************************************/
size_t nBytesCode(const char ch){
    if(ch & (1 << 7)){
        int nBytes = 1;
        for(int idx = 0; idx != 6; ++idx){
            if(ch & (1 << (6 - idx))){
                ++nBytes;	
            }else
                break;
        }
        return nBytes;
    }
    return 1;
}  

std::size_t length(const std::string &str){
    std::size_t ilen = 0;
    for(std::size_t idx = 0; idx != str.size(); ++idx){
        int nBytes = nBytesCode(str[idx]);
        idx += (nBytes - 1);
        ++ilen;
    }
    return ilen;
}

int triple_min(const int &a, const int &b, const int &c){
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

//计算最小编辑距离-包括处理中英文
int editDistance(const std::string & lhs, const std::string &rhs){
    size_t lhs_len = length(lhs);
    size_t rhs_len = length(rhs);
    int editDist[lhs_len + 1][rhs_len + 1];
    for(size_t idx = 0; idx <= lhs_len; ++idx){
        editDist[idx][0] = idx;
    }

    for(size_t idx = 0; idx <= rhs_len; ++idx){
        editDist[0][idx] = idx;
    }

    std::string sublhs, subrhs;
    for(std::size_t dist_i = 1, lhs_idx = 0; dist_i <= lhs_len; ++dist_i, ++lhs_idx){
        size_t nBytes = nBytesCode(lhs[lhs_idx]);
        sublhs = lhs.substr(lhs_idx, nBytes);
        lhs_idx += (nBytes - 1);

        for(std::size_t dist_j = 1, rhs_idx = 0; dist_j <= rhs_len; ++dist_j, ++rhs_idx){
            nBytes = nBytesCode(rhs[rhs_idx]);
            subrhs = rhs.substr(rhs_idx, nBytes);
            rhs_idx += (nBytes - 1);
            if(sublhs == subrhs){
                editDist[dist_i][dist_j] = editDist[dist_i - 1][dist_j - 1];
            }
            else{
                editDist[dist_i][dist_j] = 
                    triple_min(   editDist[dist_i][dist_j - 1] + 1,
                                  editDist[dist_i - 1][dist_j] + 1,
                                  editDist[dist_i - 1][dist_j - 1] + 1);
            }
        }//for
    }//for
    return editDist[lhs_len][rhs_len];
}


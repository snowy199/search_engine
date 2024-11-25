#include <unordered_map>
#include <bitset>
#include <queue>
#include "pageLib/simHash.h"
#include "Configuration.h"


using std::priority_queue;
using std::unordered_map;
using std::bitset;

Configuration* pConfSimHash = Configuration::getInstance("conf/searchSever.conf");
map<string, string> confDataSimHash = pConfSimHash->getConfigMap();

SimHash::SimHash() {

}

SimHash::~SimHash() {

}

bool SimHash::isDuplicate(const string& simhash) {
    double sim = stod(confDataSimHash["similarity"]);
    if(_simHash.empty()){
        _simHash.push_back(simhash);
        return false;
    }
    for(auto & it : _simHash){
        int distance = hammingDistance(it, simhash);
        double similarity = 1.0 - static_cast<double>(distance)/64;
        if(similarity > sim) return true;
    }
    _simHash.push_back(simhash);
    return false;
}

string SimHash::calculateSimHash(const map<string, double> & idTfidf) {
    vector<string> keyWords = getKeyWords(idTfidf);
    
    unordered_map<string, bitset<64>> keywords_hash;
    for(auto & it : keyWords){
        std::hash<string> hasher;
        keywords_hash[it] = bitset<64>(hasher(it));
    }

    vector<double> addIdf(64);
    for(auto & it : keywords_hash){
        const string & keyword = it.first;
        const bitset<64> & keyword_hash = it.second;
        double w = idTfidf.at(keyword);
        for(size_t i = 0; i < 64; ++i){
            if(keyword_hash[i]){
                addIdf[i] += w;
            }else{
                addIdf[i] -= w;
            }
        }
    }

    bitset<64> simhash;
    for(size_t i = 0; i < 64; ++i){
        if(addIdf[i] > 0){
            simhash[i] = 1;
        }else {
            simhash[i] = 0;
        }
    } 

    
    return simhash.to_string();
}

using std::pair;
//自定义比较器，使priority_queue按照double升序排序，使用小顶堆拿到权重最大的K个词
struct Compare {
    bool operator()(const std::pair<std::string, double>& a, const std::pair<std::string, double>& b) {
        return a.second > b.second;  // 使用大于号（>）进行升序比较
    }
};

vector<string> SimHash::getKeyWords(const map<string, double> & idTfidf) {
    priority_queue<pair<string, double>, vector<pair<string, double>>, Compare> keywords_value;
    size_t K = stoi(confDataSimHash["TopK"]);
    for(auto & it : idTfidf){
        if(keywords_value.size() < K){
            keywords_value.push(std::make_pair(it.first, it.second));
        }else{
            if(it.second > keywords_value.top().second){
                keywords_value.pop();
                keywords_value.push(std::make_pair(it.first, it.second));
            }
        }
    }

    vector<string> keywords;
    while(!keywords_value.empty()){
        keywords.push_back(keywords_value.top().first);
        keywords_value.pop();
    }
    return keywords;
}

int SimHash::hammingDistance(const string& s1, const string& s2) {
    int distance = 0;
    size_t size = s1.size();
    for(size_t i = 0; i < size; ++i){
        if(s1[i] != s2[i]){
            ++distance;
        }
    }
    return distance;
}
#include "dict/dictionary.h"

#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;


void Dictionary::readDictAndIndex(const string &dict_path,const string &index_path){
    if(_isInited){
        return ;
    }
    ifstream ifs_dict(dict_path);
    if(!ifs_dict.good()){
        cout <<  "ifs_dict is't good: "<< dict_path << endl;
        return ;
    }
    string line;
        while(getline(ifs_dict,line)){
        istringstream iss(line);
        string word;
        int count;
        iss >> word;
        iss >> count;
        _dict.push_back({word,count});
    }
    ifs_dict.close();
    ifstream ifs_index(index_path);
    if(!ifs_index){
        cout <<  "ifs_dict is't good: "<< index_path << endl;
        return ;
    }
    while(getline(ifs_index,line)){
        istringstream iss(line);
        string word;
        iss >> word;
        auto p = _index_table.insert({word,set<int>()});
        if(p.second){
            int idx;
            while(iss >> idx){
                p.first->second.insert(idx);
            }
        }else{
            cout << "insert failed" << endl;
        }
    }
    ifs_index.close();
    _isInited = true;
}
vector<pair<string,int>> Dictionary::getDict(){
    return _dict;
}
map<string,set<int>> Dictionary::getIndexTable(){
    return _index_table;
}


EnDictionary * EnDictionary::_pInstance1 = nullptr;
Dictionary * EnDictionary::createInstance(){
    if(_pInstance1 == nullptr){
        _pInstance1 = new EnDictionary();
    }
    return _pInstance1;
}

CnDictionary *CnDictionary::_pInstance2 = nullptr;
Dictionary * CnDictionary::createInstance(){
    if(_pInstance2 == nullptr){
        _pInstance2 = new CnDictionary();
    }
    return _pInstance2;
}
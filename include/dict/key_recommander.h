#ifndef __KEY_RECOMMANDER_H__
#define __KEY_RECOMMANDER_H__

#include "../../include/dict/dictionary.h"
#include<string>
#include<queue>
using namespace std;

class CandidateResult{
public:
    CandidateResult(const string &wordCandidate,int freq,int dist);
public:
    string _wordCandidate;//候选词
    int _freq;//词频
    int _dist;//与查询词的编辑距离
};

bool operator<(const CandidateResult &lhs,const CandidateResult &rhs);

class KeyRecommander{
public:
    KeyRecommander(const string &word);
    //调用doQuery()返回一个字符串 字符串包含5个词
    virtual string query(int tNum);
    //实际查询的函数   返回一个包含5个词的vector
    virtual vector<string> doQuery() = 0;
    
protected:
    string _wordBeQuery;//要查询的词
    priority_queue<CandidateResult> _prique;//候选词优先队列
    Dictionary *dictionary;
};

//查询英文推荐词
class EnKeyRecommander : public KeyRecommander{
public:
    EnKeyRecommander(const string &word);
    vector<string> doQuery() override;
};

//查询中文推荐词
class CnKeyRecommander : public KeyRecommander{
public:
    CnKeyRecommander(const string &word);
    vector<string> doQuery() override;
};

#endif

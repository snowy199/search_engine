#ifndef __SPLIT_TOOL_H__
#define __SPLIT_TOOL_H__
#include "../cppjieba/Jieba.hpp"
#include<string>
#include<vector>
#include<unordered_set>
using std::string;
using std::vector;
using std::unordered_set;


class SplitTool{
public:
    virtual vector<string> cut(const string &str) = 0;
    virtual vector<string> removeStopWords(vector<string> & words) = 0;

};


class EnSplitTool : public SplitTool{
public:
    vector<string> cut(const string &str) override;
    vector<string> removeStopWords(vector<string> & words) override{
        return words;
    }

private:
    static void handleLine(string &line);
};

class CnSplitTool : public SplitTool{
public:
    CnSplitTool(const char * const dict_path,const char * const hmm_path,
                const char * const user_dict_path,const char * const idf_path,
                const char * const stop_word_path);
    vector<string> cut(const string &str) override;
    vector<string> removeStopWords(vector<string> & words) override;

private:
    const char * const _dict_path;
    const char * const _hmm_path;
    const char * const _user_dict_path;
    const char * const _idf_path;
    const char * const _stop_word_path;
    unordered_set<string> _stopWords;
    static cppjieba::Jieba * jieba;

    unordered_set<string> createStopWordsSet();
};

#endif
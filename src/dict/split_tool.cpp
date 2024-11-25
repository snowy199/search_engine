#include "dict/split_tool.h"
#include "mylog.h"
#include <cctype>
#include <sstream>
#include <fstream>

using std::istringstream;
using std::ifstream;
using Mylog = mylog::Mylogger;

/*将大写字母处理成小写 非字符处理成空格*/
void EnSplitTool::handleLine(string &line){
    for(auto &c : line){
        if(!isalpha(c)){
            c = ' ';
        }else if(c >= 'A' && c <= 'Z'){
            c = 'a' + c - 'A';
        }
    }    
}

vector<string> EnSplitTool::cut(const string &str){
    vector<string> vec;
    string line = str;
    handleLine(line);
    istringstream iss(line);
    
    string word;
    while(iss >> word){
        vec.push_back(word);
    }
    return vec;
}

cppjieba::Jieba *CnSplitTool::jieba = nullptr; 

CnSplitTool::CnSplitTool(const char * const dict_path,const char * const hmm_path,
                         const char * const user_dict_path,const char * const idf_path,
                         const char * const stop_word_path)
: _dict_path(dict_path)
, _hmm_path(hmm_path)
, _user_dict_path(user_dict_path)
, _idf_path(idf_path)
, _stop_word_path(stop_word_path)
,_stopWords(createStopWordsSet())
{
    if(jieba == nullptr){
        jieba = new cppjieba::Jieba(_dict_path,_hmm_path,_user_dict_path,
                                    _idf_path,_stop_word_path);
    }

}

vector<string> CnSplitTool::cut(const string &str){
    vector<string> vec;
    jieba->Cut(str,vec,true);
    return vec;
}

unordered_set<string> CnSplitTool::createStopWordsSet(){
    unordered_set<string> tmp;
    //读入中文停用词文件
    ifstream ifs(_stop_word_path);
    if(!ifs.good())
    {
        string error = Mylog::getErrorMsg(errno);
        LogError("stop_word_path open failed: %s : %s", error.c_str(), _stop_word_path);
    }

    string word;
    while(getline(ifs, word)){
        tmp.insert(word);
    }

    ifs.close();

    return tmp;
}

vector<string> CnSplitTool::removeStopWords(vector<string> & words){
    vector<string> tmp;
    for(auto & it : words){
        if(_stopWords.find(it) == _stopWords.end()){
            tmp.push_back(it);
        }
    }
    return tmp;
}
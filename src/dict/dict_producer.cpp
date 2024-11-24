#include "dict/dict_producer.h"

#include <dirent.h>
#include <fstream>
using namespace std;

const char* const DICT_PATH = "include/cppjieba/dict/jieba.dict.utf8";
const char* const HMM_PATH = "include/cppjieba/dict/hmm_model.utf8";
const char* const USER_DICT_PATH = "include/cppjieba/dict/user.dict.utf8";
const char* const IDF_PATH = "include/cppjieba/dict/idf.utf8";
const char* const STOP_WORD_PATH = "include/cppjieba/dict/stop_words.utf8";

DictProducer::DictProducer(const string &yuliao_path,const string &stop_word_path){
    DIR *pdir = opendir(yuliao_path.c_str());

    struct dirent *pdirent;
    while((pdirent = readdir(pdir)) != nullptr){
        if(strcmp(pdirent->d_name,".") == 0 || strcmp(pdirent->d_name,"..") == 0){
            continue;
        }
        _files.push_back(yuliao_path + "/" + pdirent->d_name);
    }
    closedir(pdir);

    ifstream ifs(stop_word_path);
    string word;
    while(ifs >> word){
        _stop_word.insert(word);
    }
    ifs.close();
}

void DictProducer::showFiles() const{//打印文件，调试用
    for(auto &file : _files){
        cout << file << endl;
    } 
}
void DictProducer::showDict() const{//打印字典，调试用
    for(auto &p : _dict){
        cout << p.first << " " << p.second << endl;
    } 
}

EnDictProducer::EnDictProducer(const string &ENyuliao_path,const string &stop_word_path)
    : DictProducer(ENyuliao_path,stop_word_path)
{  }

void EnDictProducer::buildDict() {
    map<string,int> dict_map;
    _splict_tool = new EnSplitTool();
    //遍历每个文件
    for(auto &file : _files){
        ifstream ifs(file);
        string line;
        //每次读取一行
        while(getline(ifs,line)){
            vector<string> words;
            words = _splict_tool->cut(line);
            //将每个词放入map中
            for(auto &word : words){
                if(_stop_word.find(word) != _stop_word.end()){
                    continue;
                }
                auto iter = dict_map.find(word);
                if(iter == dict_map.end()){
                    dict_map.insert({word,1});
                }else{
                    ++iter->second;
                }
            }
        }
    }

    //将map中的单词放入vector中
    for(auto &p : dict_map){
        _dict.push_back({p.first,p.second});
    }
}

void EnDictProducer::createIndex() {
    //遍历Dict
    for(int i = 0; i < _dict.size(); ++i){
        //每次取出一个词，遍历其字母，并将其放入对应字母的集合里
        for(auto c : _dict[i].first){
            auto iter = _index.find(string(1,c));
            //如果是不存在的字母，插入这个字母
            if(iter == _index.end()){
                auto pos = _index.insert({string(1,c),set<int>()});
                if(pos.second){
                    pos.first->second.insert(i);
                }
                //存在的字母，直接插入即可
            }else{
                iter->second.insert(i);
            }
        }
    }
}


CnDictProducer::CnDictProducer(const string &CNyuliao_path,const string &stop_word_path)
    : DictProducer(CNyuliao_path,stop_word_path)
{  }

void CnDictProducer::buildDict() {
    map<string,int> dict_map;
    _splict_tool = new CnSplitTool(DICT_PATH,HMM_PATH,USER_DICT_PATH,IDF_PATH,STOP_WORD_PATH);
    //遍历每个文件
    for(auto &file : _files){
        ifstream ifs(file);
        string line;
        //读文件，每次读一行
        while(getline(ifs,line)){
            //使用vector<string>保存分词出来的词
            vector<string> words;
            words = _splict_tool->cut(line);
            //将分词出来的词放入map中
            for(auto &word : words){
                if((word.front() & 0x80) == 0){//去掉ASCII码
                    continue;
                }
                //skip stop_word
                if(_stop_word.find(word) != _stop_word.end()){
                    continue;
                }
                auto iter = dict_map.find(word);
                if(iter == dict_map.end()){
                    dict_map.insert({word,1});
                }else{
                    ++iter->second;
                }
            } 
        }//while
    }//遍历每个文件结束

    //将map中的单词放入vector中
    for(auto &p : dict_map){
        _dict.push_back({p.first,p.second});
    }
}

void CnDictProducer::createIndex() {
    int i = 0;//记录下标
    for(auto elem : _dict){
        string word = elem.first;
        size_t charNums = word.size()/getByteNum_UTF8(word[0]);
        for(size_t idx = 0,n = 0; n != charNums; ++idx,++n){//得到字符数
            //按照字符个数切割
            size_t charLen = getByteNum_UTF8(word[idx]);
            string subWord = word.substr(idx,charLen);//按照编码格式进行拆分
            _index[subWord].insert(i);
            idx += (charLen - 1);
        }
        ++i;
    }
}
size_t DictProducer::getByteNum_UTF8(const char byte){
    int byteNum = 0;
    for(size_t i=0;i < 6; ++i){
        if(byte & (1 << (7 - i)))
            ++byteNum;
        else
            break;
    }
    return byteNum == 0 ? 1 : byteNum;
}

void DictProducer::store(const string &storeDict_path,const string &storeIndex_path){
    /*存储词典*/
    ofstream ofs_dict(storeDict_path);
    if(!ofs_dict.good()){
        cout << "ofs_dict failed" << endl;
        return ;
    }
    for(auto &p : _dict){
        ofs_dict << p.first << " " << p.second << endl;
    }
    ofs_dict.close();

    /*存储索引文件*/
    ofstream ofs_index(storeIndex_path);
    if(!ofs_index.good()){
        cout << "ofs_index failed" << endl;
        return ;
    }
    for(auto &p : _index){
        ofs_index << p.first;
        for(auto &idx : p.second){
            ofs_index << " " << idx;
        }
        ofs_index << endl;
    }
    ofs_index.close();
}

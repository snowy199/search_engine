#ifndef __DICT_PRODUCER_H__
#define __DICT_PRODUCER_H__

#include "split_tool.h"
#include<string>
#include<vector>
#include<set>
#include<map>
using std::string;
using std::vector;
using std::set;
using std::map;
using std::pair;

class DictProducer{
public:
    DictProducer(const string &yuliao_path,const string &stop_word_path);
    virtual void buildDict() = 0;
    virtual void createIndex() = 0;
    virtual void store(const string &storeDict_path,const string &storeIndex_path);

    void showFiles() const;//打印文件，调试用
    void showDict() const;//打印字典，调试用

protected:
    vector<string> _files;//存放文件
    vector<pair<string,int>> _dict;//字典 格式：字词 词频
    set<string> _stop_word;//停用词
    map<string,set<int>> _index;//每个字对应词 所在的行（也就是索引）
    SplitTool *_splict_tool;//分词工具

protected:
    size_t getByteNum_UTF8(const char byte);
};


class EnDictProducer : public DictProducer{
public:
    EnDictProducer(const string &ENyuliao_path,const string &stop_word_path);
    void buildDict() override;
    void createIndex() override; 
};

class CnDictProducer : public DictProducer{
public:
    CnDictProducer(const string &CNyuliao_path,const string &stop_word_path);
    void buildDict() override;
    void createIndex() override;
};

#endif
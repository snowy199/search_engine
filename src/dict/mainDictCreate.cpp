#include<iostream>
#include "dict/dict_producer.h"
#include "Configuration.h"

int main(){

    /*中文*/
    //CnDictProducer cn_dict(conf->_configMap["cn_art"],conf->_configMap["cn_stop_words_path"]);
    CnDictProducer cn_dict("data/cn_art","data/stop_words_zh.txt");
    cn_dict.showFiles();

    cn_dict.buildDict();
    cn_dict.createIndex();
    cn_dict.store("data/cn_dict.dat","data/cn_index.dat");

    /*英文*/
    //EnDictProducer en_dict(conf->_configMap["en_art"],conf->_configMap["en_stop_words_path"]);
    EnDictProducer en_dict("data/en_art","data/stop_words_eng.txt");
    en_dict.showFiles();

    en_dict.buildDict();
    en_dict.createIndex();

    en_dict.store("data/en_dict.dat","data/en_index.dat");
}
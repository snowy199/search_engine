#include "tcpServer/Task.h"
#include "webPage/WebPageQuery.h"
#include "dict/key_recommander.h"
#include "tcpServer/TcpConnection.h"
#include "nlohmann/json.hpp"
#include "mylog.h"
#include "Configuration.h"
#include <cctype>

/**
 * Task implementation
 */
Configuration* pConf = Configuration::getInstance("conf/searchSever.conf");
map<string,string> confInfo = pConf->getConfigMap();
/**
 * @param pCon
 * @param msg
 * @param webQuery
 * @param keyRecommand
 */
Task::Task(TcpConnectionPtr pCon, const string & msg)
:_pCon(pCon)
,_msg(msg)
{}


/**
 * @return void
 */
using json = nlohmann::json;
void Task::pocess(int tNum) {
    string result;

    json msgJson = json::parse(_msg); 
    string msgId = msgJson["messageId"];
    string msg = msgJson["message"];
    //"1" for keywords "2" for search
    if(msgId == "1"){
        if(!isEnglish(msg) && !isNotEnglish(msg)){
            result = packMessage("-1", "Please enter English or Chinese");
            LogInfo("Thread %d: KeyRecommend: %s, wrong input", tNum, msg.c_str());
        }else if(isEnglish(msg)){
            EnKeyRecommander enKey(msg);
            result = enKey.query(tNum);
        }else{
            CnKeyRecommander cnKey(msg);
            result = cnKey.query(tNum);
        }
        LogInfo("Thread %d: KeyRecommend: %s, result sendback", tNum, msg.c_str());
    }else if(msgId == "2"){
        LogInfo("search started")
       WebPageQuery webQuery;
       json resJson = webQuery.Query(msg);
       vector<json> item = resJson["item"];
       LogInfo("item");
       if(item.size() == 0){
           result = packMessage("-1", "No results found for the search query.");
       }else{
           result = resJson.dump();
       }
        LogInfo("Thread %d: Search: %s, %ld %s founded", tNum,msg.c_str(), item.size(), 
                                                         (item.size() > 1 ? "results" : "result"));
    }

    _pCon->addSendBc(result);
    return;
}

string Task::packMessage(const string & msgId, const string & msg){
    json msgJson;
    msgJson["messageId"] = msgId;
    msgJson["message"] = msg;

    return msgJson.dump();
}

bool Task::isEnglish(const string & msg){
    for(auto & ch : msg){
        if(!std::isalpha(ch) && ch != ' '){
            return false;
        }
    }
    return true;
}

bool Task::isNotEnglish(const string & msg){
    for(auto & ch : msg){
        if(std::isalpha(ch)){
            return false;
        }
    }
    return true;
}


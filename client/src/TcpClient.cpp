#include "include/TcpClient.h"
#include "include/Configuration.h"
#include "include/Connection.h"
#include "include/nlohmann/json.hpp"
#include <map>
#include <iostream>
#include <vector>

using std::map;
using std::vector;
using json = nlohmann::json;
/**
 * TcpClient implementation
 */


/**
 * @param conf
 */
TcpClient::TcpClient(Configuration& conf) 
:_tcpConn(connection(conf)){
}

TcpClient::~TcpClient() {

}

/**
 * @return void
 */
void TcpClient::start() {
    while(1){
        string msg = sendForKeyWrods();
        int ret = handleMsg(msg);
        if(ret == -1) continue;
        msg.clear();
        msg = sendForPages();
        handleMsg(msg);
    }
    return;
}

int TcpClient::connection(Configuration& conf){
    Connection conn(conf.getConfigMap()["ip"],
                    static_cast<unsigned short>(std::stoul(conf.getConfigMap()["port"])));
    return conn.fd();
}

string TcpClient::sendForKeyWrods(){
    string input;
    std::cout << "Enter a string and we'll get some keywords for you" << std::endl;
    std::getline(std::cin, input);
    //输入ctrl+D退出
    if(std::cin.eof()){
        std::cout << "Exit" << std::endl;
        exit(1);
    }
    string msg = packMessage("1", input);//"1" for keywords recommand
    _tcpConn.send(msg);
    
    return _tcpConn.receive();
}

string TcpClient::sendForPages(){
    string input;
    std::cout << "Search: " << std::endl;
    std::getline(std::cin, input);

    //输入ctrl+D退出
    if(std::cin.eof()){
        std::cout << "Exit" << std::endl;
        exit(1);
    }

    string msg = packMessage("2", input);//"2" for search
    _tcpConn.send(msg);

    return _tcpConn.receive();
}


int TcpClient::handleMsg(const string & msg){
    json msgJson = json::parse(msg);
    //100 for keywords 200 for webpages -1 for error 
    if(msgJson["messageId"] == "100"){
        vector<string> keywords = msgJson["keywords"];
        std::cout << "KEYWORDS: " << std::endl;
        for(auto & keyword : keywords){
            std::cout << keyword << std::endl;
        }

        return 0;
    }else if(msgJson["messageId"] == "200"){
        vector<json> items = msgJson["item"];
        int page = 0;
        int size = items.size();
        bool exit = false;

        do{
            //每次展示pageSize个网页
            for(int i = page*pageSize; i < size && i < (page+1)*pageSize; ++i){
                string title = items[i]["title"];
                string link = items[i]["link"];
                string content = items[i]["content"];
                std::cout << title << std::endl
                          << link << std::endl
                          << content << std::endl;
            }


            int totalPage = size/pageSize + (size % pageSize != 0);
            displayPageNavifation(page + 1, totalPage);
            
            string changePage;
            while(1){
                //“<”向左翻页, ">"向右翻页 "q"退出重新搜索 不区分大小写
                std::cin >> changePage;
                if(changePage == "," || changePage == "<"){
                    if(page != 0){
                        --page;
                    }
                    break;
                }else if(changePage == "." || changePage == ">"){
                    if(page < totalPage -1) {
                        ++page;
                    }
                    break;
                }else if(changePage == "q" || changePage == "Q"){
                    exit = true;
                    break;
                }else{
                    std::cout << "'<' for left page, '>' for right page, 'q' for quit" << std::endl;
                }
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除换行符及其他无效字符
        }while(!exit);

        return 0;
    }else if(msgJson["messageId"] == "-1"){
        string msg = msgJson["message"];
        std::cout << msg << std::endl;
        return -1;
    }
    return -1;
}   

string TcpClient::packMessage(const string & msgId, const string & msg){
    json msgJson;
    msgJson["messageId"] = msgId;
    msgJson["message"] = msg;
    return msgJson.dump();
}

void TcpClient::displayPageNavifation(int curPage, int totalPage){
    std::cout << "[<]  ";
    for(int i = 1; i <= totalPage; ++i){
        if(i == curPage){
            std::cout << "\033[1;97m" << curPage << "\033[0m" << " ";
        }else{
            std::cout << i << " ";
        }
    }
    std::cout << " [>]" << std::endl;
}


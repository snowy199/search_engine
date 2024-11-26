/**
 * Project SearchEngine
 */


#ifndef _TCPCLIENT_H
#define _TCPCLIENT_H
#include "TcpConnection.h"
#include "Connection.h"

class Configuration;

class TcpClient {
public: 
/**
 * @param conf
 */
TcpClient(Configuration& conf);
    
~TcpClient();
    
void start();
private:
TcpConnection _tcpConn;
const int pageSize = 10;//单词展示的网页数上限    

int connection(Configuration& conf);

//发送消息从而获得推荐的关键词
string sendForKeyWrods();
//发送消息并接收搜索结果
string sendForPages();

//处理收到的message
int handleMsg(const string & msg);

//展示翻页信息
void displayPageNavifation(int curPage, int totalPage);

//将消息封装成json并转成string
string packMessage(const string & msgId, const string & msg);

};

#endif //_TCPCLIENT_H

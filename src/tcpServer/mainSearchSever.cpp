#include <iostream>
#include "tcpServer/SearchServer.h"
#include "Configuration.h"
#include "mylog.h"



using namespace std;
int main()
{
    Configuration* pConf = Configuration::getInstance("conf/searchSever.conf"); 

    mylog::Mylogger::getInstance("root");
    SearchServer server(*pConf);
    cout << "sever init" << endl;
    server.start();
    return 0;
}


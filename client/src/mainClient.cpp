#include <iostream>
#include "include/TcpClient.h"
#include "include/Configuration.h"

int main()
{
    Configuration* pCon = Configuration::getInstance("client/conf/client.conf");
    std::cout << "Configuration" << std::endl;
    TcpClient client(*pCon);
    client.start();
    return 0;
}


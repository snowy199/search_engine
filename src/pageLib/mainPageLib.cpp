#include <iostream>
#include "pageLib/pageLib.h"
#include "mylog.h"

using std::cout;
using std::endl;
using Mylog = mylog::Mylogger;

int main()
{
    Mylog::getInstance("root");
    Configuration* pconf = Configuration::getInstance("conf/searchSever.conf");
    PageLib pageLib(*pconf);
    pageLib.create();
    pageLib.store();
    return 0;
}
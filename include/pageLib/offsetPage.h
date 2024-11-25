#ifndef __OFFSETPAGE__
#define __OFFSETPAGE__
#include "Configuration.h"
#include "pageLib/webPage.h"
#include <fstream>
using namespace std;

// OffsetPage类用于处理和存储来自WebPages的数据
class OffsetPage {
public:
    // 构造函数，接收Configuration和WebPages的引用
    OffsetPage(Configuration& conf, WebPages& webPage);

    // store函数用于获取，处理并存储数据
    void store();

    // 析构函数，无特殊操作
    ~OffsetPage();

private:
    // 私有成员变量，分别保存Configuration和WebPages的引用
    Configuration& _configuration;
    WebPages& _webPage;
};

#endif
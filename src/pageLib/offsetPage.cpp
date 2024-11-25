#include "pageLib/offsetPage.h"
#include "mylog.h"    // 引入日志的头文件
#include <cstddef>
#include <iostream>
#include <map>
#include <ostream>
#include <vector>
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::streampos;
using std::string;

OffsetPage::OffsetPage(Configuration& conf, WebPages& webPage)
    : _configuration(conf), _webPage(webPage) {
}

void OffsetPage::store() {
    // 从Configuration对象获取配置数据
    std::map<string, string> config_data = _configuration.getConfigMap();

    // 创建一个文件输出流，文件路径由Configuration对象提供
    ofstream ofs(config_data["OffsetPage.dat"]);
    if(!ofs.good()) {
        LogError("Failed to open offset file: %s", config_data["OffsetPage.dat"].c_str());    // 记录错误信息
        return;
    }

    // 从WebPages对象获取文章数量
    size_t size = _webPage.getSize();

    // 初始化偏移量和长度
    streampos offset = 0;

    // 遍历webPage
    for(size_t i = 0; i < size; ++i) {
        // 获取第i个doc的内容
        string content = _webPage.getPage(i);
        // 获取内容的长度
        int length = content.size();
        // 写入docid，偏移量和长度
        ofs << i + 1 << " " << offset << " " << length << endl;
        // 更新偏移量
        offset += length;
    }
    if(ofs.fail()) {
        LogError("Failed to write to file %s", config_data["OffsetPage.dat"].c_str());    // 记录错误信息
    }
}

OffsetPage::~OffsetPage() {
}
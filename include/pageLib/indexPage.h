#ifndef __INDEXPAGE__
#define __INDEXPAGE__

#include "Configuration.h"
#include "pageLib/webPage.h"
#include <fstream>
using std::cout;
using std::endl;
class IndexPage {
public:
    IndexPage(Configuration& conf, WebPages& webPage)
            : _configuration(conf),
            _webPage(webPage) {}

     void store() {
        map<string, string> config_data = _configuration.getConfigMap();
        map<int, map<string, double>> webPage_data = _webPage.getTfidf();
        map<string, map<int, double>> res;

        std::ofstream ofs(config_data["IndexPage.dat"]);
        if (!ofs.good()) {
            cout << "IndexPage::ofs is not good." << std::endl;
            return;
        }

        // 构建索引页数据
        for (auto i : webPage_data) {
            for (auto j : i.second) {
                if (res.find(j.first) == res.end()) {
                    res[j.first] = {};
                }
                res[j.first].insert({i.first, j.second});
            }
        }

        // 将索引页数据写入文件
        for (auto i : res) {
            ofs << i.first << " ";
            for (auto j : i.second) {
                ofs << j.first << " " << j.second << " ";
            }
            ofs << endl;
        }
    }
    ~IndexPage() {}

private:
    Configuration& _configuration;  // Configuration 对象的引用
    WebPages& _webPage;  // WebPages 对象的引用
};
#endif
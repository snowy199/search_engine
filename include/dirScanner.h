#ifndef __dirScanner__
#define __dirScanner__

#include<iostream>
#include<string>
#include<vector>
#include<string>
#include<dirent.h>
#include <cstring>
#include "Configuration.h"

using namespace std;

class DirScanner {
public:
     DirScanner(Configuration& conf)
        : _dirPath(conf.getConfigMap()["dirPath"])
    {
        DIR* dir;
        struct dirent* entry;

        const char* directoryPath = _dirPath.c_str();  // 目录路径

        dir = opendir(directoryPath);
        if (dir) {
            // 遍历目录中的文件
            while ((entry = readdir(dir)) != nullptr) {
                // 仅处理普通文件且文件名包含 ".xml" 的文件
                if (entry->d_type == DT_REG && std::strstr(entry->d_name, ".xml")) {
                    _filelist.push_back(_dirPath + "/" + entry->d_name);  // 将符合条件的文件路径添加到文件列表中
                }
            }
            closedir(dir);
        }
    }

        ~DirScanner() {}

    // 获取文件列表
    vector<string>& getFilelist()
    {
        return _filelist;
    }

    // 显示文件列表
    void showFilelist()
    {
        for (const auto& file : _filelist) {
            std::cout << file << std::endl;
        }
    }
private:
    vector<string> _filelist;  // 存储文件列表
    string _dirPath;  // 目录路径
};

#endif
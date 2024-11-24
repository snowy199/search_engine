#ifndef __CONFIGURATION__
#define __CONFIGURATION__

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>

class Configuration {
public:
    // 获取 Configuration 的单例实例
    static Configuration* getInstance(const std::string& confPath);

    // 析构函数
    ~Configuration();

    // 显示配置映射
    void showConfigMap();

    // 获取配置映射
    std::map<std::string, std::string> getConfigMap();

private:
    // 私有构造函数，接受配置文件路径作为参数
    Configuration(const std::string& confPath);

    // 加载配置文件
    void loadConfigFile();

private:
    static Configuration* _pConf;  // Configuration 单例对象指针
    std::string _confPath;  // 配置文件路径
public:
    std::map<std::string, std::string> _configMap;  // 配置映射，存储配置项和对应的值


};

#endif


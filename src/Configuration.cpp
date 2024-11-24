#include "Configuration.h"
using namespace std;

// 初始化静态成员变量
Configuration* Configuration::_pConf = nullptr;

// 构造函数，接收配置文件路径作为参数
Configuration::Configuration(const std::string& confPath)
    : _confPath(confPath)
{
    // 加载配置文件
    loadConfigFile();
}

// 析构函数
Configuration::~Configuration() {}

// 获取 Configuration 单例对象的方法
Configuration* Configuration::getInstance(const std::string& confPath)
{
    if (_pConf == nullptr)
    {
        // 若单例对象不存在，则创建新的对象
        _pConf = new Configuration(confPath);
        cout << "Configuration:" << confPath << endl;
    }
    return _pConf;
}

// 加载配置文件
void Configuration::loadConfigFile()
{
    // 打开配置文件
    std::ifstream ifs(_confPath);
    if (!ifs.good())
    {
        // 若打开失败，则输出错误信息并返回
        std::cout << "Configuration::loadConfigFile: Failed to open file: " << _confPath << std::endl;
        return;
    }

    std::string line;
    while (std::getline(ifs, line))
    {
        // 逐行读取配置文件内容
        std::istringstream iss(line);
        std::string key;
        std::string value;
        if (iss >> key >> value)
        {
            // 解析每一行的键值对，并存入配置映射中
            _configMap[key] = value;
        }
    }
}

// 显示配置映射中的内容
void Configuration::showConfigMap()
{
    for(auto i:_configMap)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
}

// 获取配置映射
std::map<std::string, std::string> Configuration::getConfigMap(){
    return _configMap;
}


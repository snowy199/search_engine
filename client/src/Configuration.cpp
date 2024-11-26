#include "Configuration.h"
using namespace std;

Configuration* Configuration::_pConf = nullptr;

Configuration::Configuration(const std::string& confPath)
    : _confPath(confPath)
{
    loadConfigFile();

}

Configuration::~Configuration() {}

Configuration* Configuration::getInstance(const std::string& confPath)
{
    if (_pConf == nullptr)
    {
        _pConf = new Configuration(confPath);
        cout << "Configuration" << endl;

    }
    return _pConf;

}

void Configuration::loadConfigFile()
{
    std::ifstream ifs(_confPath);
    if (!ifs.good())
    {
        std::cout << "Configuration::loadConfigFile: Failed to open file." << std::endl;
        return;

    }

    std::string line;
    while (std::getline(ifs, line))
    {
        std::istringstream iss(line);
        std::string key;
        std::string value;
        if (iss >> key >> value)
        {
            _configMap[key] = value;

        }

    }
}

    void Configuration::showConfigMap()
    {
        for(auto i:_configMap)
        {
            cout<<i.first<<" "<<i.second<<endl;
        }
    }
std::map<std::string, std::string> Configuration::getConfigMap(){
    return _configMap;
}

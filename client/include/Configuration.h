#ifndef __CONFIGURATION__
#define __CONFIGURATION__

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>

class Configuration
{
public:
    static Configuration* getInstance(const std::string& confPath);
    ~Configuration();
    void showConfigMap();
    std::map<std::string, std::string> getConfigMap();

private:
    Configuration(const std::string& confPath);
    void loadConfigFile();

private:
    static Configuration* _pConf;
    std::string _confPath;
public:
    std::map<std::string, std::string> _configMap;

};

#endif


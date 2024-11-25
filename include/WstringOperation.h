#ifndef WSTRINGOPERATION
#define WSTRINGOPERATION

#include <iostream>
#include <codecvt>
#include <cwchar>
#include <vector>
#include <string>
#include <locale>
#include <sstream>
#include <algorithm>
#include <map>

class WstringOperation {
public:
    // 在 wstring 中查找指定字符的位置
    static std::size_t findCharacter(const std::wstring& str, const std::string& character, std::size_t startPos = 0) {
        std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
        std::wstring wcharCharacter = converter.from_bytes(character);

        std::size_t length = str.length();
        std::size_t i = startPos;

        while (i < length) {
            if (str[i] == wcharCharacter[0]) {
                return i;
            }
            ++i;
        }

        return std::wstring::npos; // 未找到字符
    }

    // 在 wstring 中查找所有指定字符的位置
    static std::vector<std::size_t> findAllOccurrences(const std::wstring& str, const std::string& character, std::size_t startPos = 0) {
        std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
        std::wstring wcharCharacter = converter.from_bytes(character);

        std::size_t length = str.length();
        std::size_t wlength = wcharCharacter.length();
        std::size_t i = startPos;

        std::vector<std::size_t> occurrences; // 存储匹配的索引
        int count = 0;
        while (i < length) {
            if (str[i] == wcharCharacter[0]) {
                int flag = 1;
                for (std::size_t j = 1; j < wlength; j++) {
                    if (str[i + j] != wcharCharacter[j]) {
                        flag = 0;
                    }
                }
                if (flag == 1) {
                    occurrences.push_back(i);
                    ++count;
                    if (count == 5) {
                        return occurrences;
                    }
                }
            }
            ++i;
        }

        return occurrences;
    }

    // 根据指定的起始位置和长度截取 wstring 子串
    static std::wstring substrByCharacter(const std::wstring& str, std::size_t startPos, std::size_t length) {
        std::wstring subStr;

        if (startPos < str.length()) {
            subStr = str.substr(startPos, length);
        }

        return subStr;
    }

    // 将 string 转换为 wstring
    static std::wstring stringToWstring(const std::string& str) {
        std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
        return converter.from_bytes(str);
    }

    // 将 wstring 转换为 string
    static std::string wstringToString(const std::wstring& wstr) {
        std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
        return converter.to_bytes(wstr);
    }

    // 移除字符串中的空白字符
    static std::string removeWhitespace(const std::string& str) {
        std::string result;
        result.reserve(str.size());

        for (char c : str) {
            if (!std::isspace(static_cast<unsigned char>(c))) {
                result.push_back(c);
            }
        }

        return result;
    }

    // 将 vector 转换为 string
    template<typename T>
        static std::string vectorToString(const std::vector<T>& vec) {
            std::stringstream ss;
            for (const auto& num : vec) {
                ss << num << " ";
            }
            return ss.str();
        }

    // 将 string 转换为 vector
    static std::vector<int> stringToVector(const std::string& str) {
        std::vector<int> vec;
        std::stringstream ss(str);
        int num;
        while (ss >> num) {
            vec.push_back(num);
        }
        return vec;
    }

    // 将 map 转换为 string
    static std::string mapToString(const std::map<int, double>& myMap) {
        std::ostringstream oss;
        for (const auto& pair : myMap) {
            oss << pair.first << ":" << pair.second << ";";
        }
        return oss.str();
    }

    // 将 string 转换为 map
    static std::map<int, double> stringToMap(const std::string& str) {
        std::map<int, double> myMap;
        std::istringstream iss(str);
        std::string pairString;
        while (std::getline(iss, pairString, ';')) {
            std::istringstream pairIss(pairString);
            int key;
            double value;
            char separator;
            if (pairIss >> key >> separator >> value && separator == ':') {
                myMap[key] = value;
            }
        }
        return myMap;
    }

private:
    WstringOperation() {}
    ~WstringOperation() {}
};

#endif  // WSTRINGOPERATION


#ifndef CHANGECOLOR
#define CHANGECOLOR

#include <iostream>
#include <string>

// 常量定义，用于设置颜色
const std::wstring RED_COLOR = L"\033[1;31m";         // 红色
const std::wstring BLUE_COLOR = L"\033[1;34m";        // 蓝色
const std::wstring GREEN_COLOR = L"\033[1;32m";       // 绿色
const std::wstring RESET_COLOR = L"\033[0m";          // 重置颜色

const std::string BLUE_COLOR_STRING = "\033[1;34m";    // 蓝色 (字符串版本)
const std::string GREEN_COLOR_STRING = "\033[1;32m";   // 绿色 (字符串版本)
const std::string RESET_COLOR_STRING = "\033[0m";      // 重置颜色 (字符串版本)

class ChangeColor {
public:
    // 在给定的字符串中添加颜色，返回带有颜色的字符串
    static std::wstring colorizeString(const std::wstring& str, std::size_t startPos, std::size_t length, const std::wstring& color) {
        std::wstring coloredStr = str;

        if (startPos < coloredStr.length()) {
            coloredStr.insert(startPos, color);
            coloredStr.insert(startPos + length + color.length(), RESET_COLOR);
        }

        return coloredStr;
    }

    // 在给定的字符串中添加颜色，返回带有颜色的字符串 (字符串版本)
    static std::string colorizeString(const std::string& str, std::size_t startPos, std::size_t length, const std::string& color) {
        std::string coloredStr = str;

        if (startPos < coloredStr.length()) {
            coloredStr.insert(startPos, color);
            coloredStr.insert(startPos + length + color.length(), RESET_COLOR_STRING);
        }

        return coloredStr;
    }

private:
    ChangeColor();
};

#endif  // CHANGECOLOR


#include <sstream>
#include <iostream>
#include "../include/parser.h"

// 输入解析函数：将命令行输入拆分为多个单独的字符串
std::vector<std::string> splitInput(const std::string& input) {
    std::vector<std::string> tokens;
    std::stringstream ss(input);
    std::string token;
    
    while (ss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

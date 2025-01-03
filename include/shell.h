#ifndef SHELL_H
#define SHELL_H

#include <string>
#include <vector>

// 命令行输入解析
std::vector<std::string> parseInput(const std::string& input);

// 执行命令
void executeCommand(const std::vector<std::string>& args);

// 打印命令行提示符
void printPrompt();

#endif // SHELL_H

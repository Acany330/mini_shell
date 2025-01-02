#include <iostream>
#include "../include/shell.h"
#include "../include/parser.h"
#include "../include/executor.h"

void printPrompt() {
    std::cout << "MiniShell> ";
}

std::vector<std::string> parseInput(const std::string& input) {
    return splitInput(input);  // 使用 parser.cpp 中的 splitInput 函数
}

void executeCommand(const std::vector<std::string>& args) {
    // 创建 args 的副本
    std::vector<std::string> args_copy = args;

    // 先处理内建命令
    handleBuiltinCommands(args_copy);  // 使用非 const 引用

    // 如果是内建命令，handleBuiltinCommands 已经处理并返回
    // 否则，执行外部命令
    if (args[0] != "cd" && args[0] != "exit") {
        executeExternalCommand(args_copy);
    }
}

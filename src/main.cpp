#include <iostream>
#include <string>
#include <vector>
#include "../include/shell.h"
#include "../include/parser.h"
#include "../include/executor.h"

int main() {
    std::string input;
    std::vector<std::string> args;

    while (true) {
        // 打印命令行提示符
        printPrompt();

        // 读取用户输入
        std::getline(std::cin, input);

        // 如果输入为空，跳过
        if (input.empty()) {
            continue;
        }

        // 解析输入
        args = parseInput(input);

        // 执行命令
        executeCommand(args);
    }

    return 0;
}

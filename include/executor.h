#ifndef EXECUTOR_H
#define EXECUTOR_H

#include <vector>
#include <string>

// 执行外部命令
void executeExternalCommand(std::vector<std::string>& args);

// 处理内建命令
void handleBuiltinCommands(std::vector<std::string>& args);

#endif // EXECUTOR_H

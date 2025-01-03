#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "../include/executor.h"

// 处理内建命令
void handleBuiltinCommands(std::vector<std::string>& args) {  // 改为非 const 引用
    if (args.empty()) return;

    // 处理 'cd' 命令
    if (args[0] == "cd") {
        if (args.size() < 2) {
            std::cerr << "cd: missing argument\n";
        } else {
            if (chdir(args[1].c_str()) != 0) {
                perror("cd");
            }
        }
        return;
    } 
    
    // 处理 'exit' 命令
    else if (args[0] == "exit") {
        std::cout << "Exiting MiniShell..." << std::endl;
        exit(0);
    }
}

// 执行外部命令
void executeExternalCommand(std::vector<std::string>& args) {
    pid_t pid = fork();
    if (pid == 0) {  // 子进程
        // 将 std::vector 转换为 const char* 数组
        std::vector<const char*> cargs;
        for (const auto& arg : args) {
            cargs.push_back(arg.c_str());
        }
        cargs.push_back(nullptr);  // execvp 需要空指针结束
        
        // 调用 execvp 执行外部命令
        execvp(cargs[0], const_cast<char**>(cargs.data()));
        
        // 如果 execvp 返回，说明出错了
        std::cerr << "Unknown command: " << args[0] << std::endl;
        exit(1);
    } else if (pid > 0) {  // 父进程
        waitpid(pid, nullptr, 0);  // 等待子进程结束
    } else {
        std::cerr << "Fork failed!" << std::endl;
    }
}

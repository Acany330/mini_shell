# 定义源文件和对象文件
SRC = src/main.cpp src/shell.cpp src/parser.cpp src/executor.cpp
OBJ = obj/main.o obj/shell.o obj/parser.o obj/executor.o
OUT = mini_shell

# 编译选项
CXX = g++
CXXFLAGS = -Wall -std=c++11 -Iinclude

# 默认目标：生成可执行文件
$(OUT): $(OBJ)
	$(CXX) $(OBJ) -o $(OUT)

# 编译 .cpp 文件为 .o 文件
obj/%.o: src
	@mkdir -p obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理目标：删除所有编译生成的文件
clean:
	rm -rf obj $(OUT)

# 伪目标：确保不会与文件名冲突
.PHONY: clean

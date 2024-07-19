# cmake最低版本号要求
cmake_minimum_required (VERSION 3.20)
# 设置PROJECT_NAME变量
set(PROJECT_NAME dataStruct-algorithm)
# 设置工程名
project (${PROJECT_NAME})
# # 查找当前目录下的所有源文件并存入DIR_SRCS变量
# aux_source_directory(src DIR_SRCS)
# 添加一个可编译的目标到工程
add_executable (1_sort app/1_sort.cpp)
add_executable(2_binary app/2_binary.cpp)
# cmake 最低版本号要求
cmake_minimum_required (VERSION 3.20)

# 设置 cpp 版本
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 设置 PROJECT_NAME 变量
set(PROJECT_NAME dataStruct-algorithm)
# 设置工程名
project (${PROJECT_NAME})

include_directories(include)

# 添加一个可编译的目标到工程
add_executable (1_sort app/1_sort.cpp)
add_executable(2_binary app/2_binary.cpp)

add_executable(3_binary_tree_travelsal app/3_binary_tree_traversal.cpp)
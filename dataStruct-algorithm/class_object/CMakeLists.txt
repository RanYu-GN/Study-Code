cmake_minimum_required(VERSION 3.26)
project(class_object)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR}/include)
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_DIR)

add_executable(class_object main.cpp ${SRC_DIR})

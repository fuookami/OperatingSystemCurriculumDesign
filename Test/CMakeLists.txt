cmake_minimum_required(VERSION 3.7.2)
project(ShellTest)

set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)
set(CMAKE_CXX_FLAGS "-std=c++11")

add_executable(app src/main.cpp)
add_subdirectory(mycat bin/mycat)
add_subdirectory(mycp bin/mycp)
add_subdirectory(myecho bin/myecho)
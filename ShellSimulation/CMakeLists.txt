cmake_minimum_required(VERSION 3.7.2)
project(ShellSimulation)

set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)
set(CMAKE_CXX_FLAGS "-std=c++11")

add_subdirectory(ShellSimulation)
add_subdirectory(mycat bin/mycat)
add_subdirectory(mycp bin/mycp)
add_subdirectory(myecho bin/myecho)
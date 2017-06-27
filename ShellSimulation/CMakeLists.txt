cmake_minimum_required(VERSION 3.7.2)
project(src/ShellSimulation)

set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)
set(CMAKE_CXX_FLAGS "-std=c++11")

add_subdirectory(src/ShellSimulation)
add_subdirectory(src/mycat bin/mycat)
add_subdirectory(src/mycp bin/mycp)
add_subdirectory(src/myecho bin/myecho)
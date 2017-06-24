cmake_minimum_required(VERSION 3.7.2)
project(ShellTest)

include_directories("usr/local/include/c++")
link_directories("usr/local/lib")

set(CMAKE_C_COMPILER    "/usr/local/bin/clang")
set(CMAKE_CXX_COMPILER  "/usr/local/bin/clang++")
set(CMAKE_CXX_FLAGS     "-std=c++14 -lpthread")

SET (CMAKE_AR      "/usr/local/bin/llvm-ar")
SET (CMAKE_LINKER  "/usr/local/bin/llvm-ld")
SET (CMAKE_NM      "/usr/local/bin/llvm-nm")
SET (CMAKE_OBJDUMP "/usr/local/bin/llvm-objdump")
SET (CMAKE_RANLIB  "/usr/local/bin/llvm-ranlib")

add_executable(app src/main.cpp)
add_subdirectory(mycat bin/mycat)
add_subdirectory(mycp bin/mycp)
add_subdirectory(myecho bin/myecho)
add_subdirectory(pi1 bin/pi1)
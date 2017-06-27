cmake_minimum_required(VERSION 3.7.2)
project(ShellSimulation)

include_directories("/usr/local/include/c++"
        ${PROJECT_SOURCE_DIR}/include/)
link_directories("/usr/local/lib"
        ${PROJECT_BINARY_DIR}/lib/)

set(CMAKE_C_COMPILER    "/usr/local/bin/clang")
set(CMAKE_CXX_COMPILER  "/usr/local/bin/clang++")
set(CMAKE_CXX_FLAGS     "-std=c++14 -lpthread")

SET (CMAKE_AR      "/usr/local/bin/llvm-ar")
SET (CMAKE_LINKER  "/usr/local/bin/llvm-ld")
SET (CMAKE_NM      "/usr/local/bin/llvm-nm")
SET (CMAKE_OBJDUMP "/usr/local/bin/llvm-objdump")
SET (CMAKE_RANLIB  "/usr/local/bin/llvm-ranlib")

add_subdirectory(src)
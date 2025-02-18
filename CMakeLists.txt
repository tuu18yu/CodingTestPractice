cmake_minimum_required(VERSION 3.5.0)
project(baekjoon VERSION 0.1.0 LANGUAGES C CXX)

set(BASIC src/basic/Baekjoon2501.h. src/basic/Baekjoon3460.h src/basic/Baekjoon10818.h)
add_executable(baekjoon main.cpp ${BASIC})
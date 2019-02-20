cmake_minimum_required(VERSION 3.13)
project(ThreadCachePool)

set(CMAKE_CXX_STANDARD 11)

add_executable(ThreadCachePool main.cpp common.h ThreadCache.cpp ThreadCache.h)
#add_executable()
cmake_minimum_required(VERSION 3.11)
project(ClionTest)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.cpp)


add_executable(ClionTest ${SOURCE_FILES})

include_directories("D:\\\\opencv3.2\\\\install\\\\include")

set(TARGET_LIBS
        "D:\\\\opencv3.2\\\\install\\\\x64\\\\mingw\\\\lib\\\\libopencv_core320.dll.a"
        "D:\\\\opencv3.2\\\\install\\\\x64\\\\mingw\\\\lib\\\\libopencv_highgui320.dll.a"
        "D:\\\\opencv3.2\\\\install\\\\x64\\\\mingw\\\\lib\\\\libopencv_imgproc320.dll.a"
        "D:\\\\opencv3.2\\\\install\\\\x64\\\\mingw\\\\lib\\\\libopencv_imgcodecs320.dll.a")

#include_directories("D:\\opencv3.2\\install\\include")
#
#set(TARGET_LIBS
#        "D:\\opencv3.2\\install\\x64\\mingw\\lib\\libopencv_core320.dll.a"
#        "D:\\opencv3.2\\install\\x64\\mingw\\lib\\libopencv_highgui320.dll.a"
#        "D:\\opencv3.2\\install\\x64\\mingw\\lib\\libopencv_imgproc320.dll.a"
#        "D:\\opencv3.2\\install\\x64\\mingw\\lib\\libopencv_imgcodecs320.dll.a")


target_link_libraries(ClionTest ${TARGET_LIBS})
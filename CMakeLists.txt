cmake_minimum_required(VERSION 3.17)
project(coroutine_demo)

include_directories(include)

set(CMAKE_CXX_STANDARD 20)

add_executable(coroutine_demo main.cpp src/CoroutineTask.cpp "include/")
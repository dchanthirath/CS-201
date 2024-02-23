cmake_minimum_required(VERSION 3.27)
project(CS_201)

set(CMAKE_CXX_STANDARD 11)

add_executable(CS_201 project/phase1/main.cpp
        project/phase1/CircularDynamicArray.cpp
        labs/main.cpp
        labs/queueu.cpp
        project/phase1/Phase1Main_S24.cpp
)
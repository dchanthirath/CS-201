cmake_minimum_required(VERSION 3.27)
project(CS_201)

set(CMAKE_CXX_STANDARD 17)

add_executable(CS_201 main.cpp
        labs/lab3/main.cpp
        labs/lab3/Queue.cpp
        labs/lab3/queueu.cpp
        project/phase1/Phase1Main_S24.cpp
        project/phase1/CircularDynamicArray.cpp
)
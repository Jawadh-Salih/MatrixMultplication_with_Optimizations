cmake_minimum_required(VERSION 3.5.1)
project(concurrent_lab3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")

set(SOURCE_FILES main.cpp Resources/Matrix.cpp Resources/MatrixMultiplier.cpp Resources/MatrixMultiplier.h Resources/util.h Resources/util.cpp)


add_executable(concurrent_lab3 ${SOURCE_FILES} Resources/Matrix.cpp Resources/Matrix.h)
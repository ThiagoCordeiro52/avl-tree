cmake_minimum_required(VERSION 3.8)
project (SearchTree VERSION 1.0.0 LANGUAGES CXX )

set(CMAKE_CXX_STANDARD 17)

include_directories(../include)
add_executable(tree test.cpp
                    tree.cpp
                    )

set(CMAKE_CXX_FLAGS "-g")

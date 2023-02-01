cmake_minimum_required(VERSION 3.24)
project(hashTables)

set(CMAKE_CXX_STANDARD 17)

add_executable(hashTables main.cpp hashTable.h hashTable.cpp player.h avl.cpp avl.h
        bst.cpp
        bst.h
        bst_node.cpp
        bst_node.h
        cmake-build-debug/t20.csv intermediate.h intermediate.cpp)

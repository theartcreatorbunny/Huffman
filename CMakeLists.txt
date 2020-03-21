cmake_minimum_required(VERSION 3.14)
project(grigrory_huffman_code)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        grigrory_huffman_code main.cpp
        src/Node.cpp
        src/Huffman.cpp
)
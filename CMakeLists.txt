cmake_minimum_required(VERSION 3.28)
project(chess)

set(CMAKE_CXX_STANDARD 26)

add_executable(chess main.cpp pieces/King.cpp board/Square.cpp)

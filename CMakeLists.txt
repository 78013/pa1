cmake_minimum_required(VERSION 3.5)
project(pa1)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp MyBoard.h MyNode.h Direction.h MyTree.h TilePosition.h)
add_executable(pa1 ${SOURCE_FILES})
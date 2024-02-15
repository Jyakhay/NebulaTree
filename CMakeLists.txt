cmake_minimum_required(VERSION 3.5)

set(NEBULA_TREE_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -static)
set(CMAKE_CXX_STANDARD 17)

project(NebulaTree)
add_subdirectory(Source)
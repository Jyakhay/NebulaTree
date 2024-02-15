cmake_minimum_required(VERSION 3.5)

set(NEBULA_TREE_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 17)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -static)
endif()

project(NebulaTree)
add_subdirectory(Source)
cmake_minimum_required (VERSION 3.0)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
include_directories(CMAKE_CURRENT_SOURCE_DIR)
add_executable (A257 A257.cpp TreeNode.cpp)
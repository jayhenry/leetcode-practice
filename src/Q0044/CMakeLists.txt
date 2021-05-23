cmake_minimum_required (VERSION 3.0)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
# add_executable (main main.cpp)
add_executable (main_dp main_dp.cpp)
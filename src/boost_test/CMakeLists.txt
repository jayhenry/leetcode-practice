cmake_minimum_required (VERSION 3.0)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++ -I D:/software/boost_1_73_0_unix")
add_executable (main main.cpp)
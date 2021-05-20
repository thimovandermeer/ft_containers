cmake_minimum_required(VERSION 3.17)
project(my_ft_containers)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(srcs)
include_directories(srcs/list)

add_executable(my_ft_containers
        srcs/list/list.hpp
        tests/listTest.cpp
        catch2.hpp srcs/stack/stack.hpp tests/stackTest.cpp)

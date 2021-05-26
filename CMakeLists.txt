cmake_minimum_required(VERSION 3.17)
project(my_ft_containers)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(srcs)
include_directories(srcs/list)

add_executable(my_ft_containers
        srcs/list/list.hpp
        tests/listTest.cpp
        srcs/stack/stack.hpp tests/stackTest.cpp srcs/queue/queue.hpp tests/queueTest.cpp srcs/vector/vector.hpp tests/vectorTest.cpp srcs/iterators/RandomAccessIterator.hpp srcs/iterators/ReverseIterator.hpp)

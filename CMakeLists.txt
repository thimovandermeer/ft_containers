cmake_minimum_required(VERSION 3.17)
project(my_ft_containers)

set(CMAKE_CXX_STANDARD 14)
set(DEBUGFLAGS "-fsanitize=address -D ASAN")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -g3 ${DEBUGFLAGS}")
set(CMAKE_LINKER_FLAGS)

add_executable( tests
        srcs/iterators/BidirectionalIterator.hpp
        srcs/iterators/RandomAccessIterator.hpp
        srcs/iterators/ReverseIterator.hpp

        srcs/list/list.hpp
        srcs/list/listNode.hpp
        srcs/map/map.hpp
        srcs/map/MapNode.hpp
        srcs/queue/queue.hpp
        srcs/stack/stack.hpp

        srcs/utils/typeTraits.hpp
        srcs/utils/utils.hpp

        srcs/vector/vector.hpp
        )

add_executable( catch
        tests/Catch2.h
        tests/catchMain.cpp
        tests/listTest.cpp
        tests/mapTest.cpp
        tests/queueTest.cpp
        tests/stackTest.cpp
        tests/vectorTest.cpp
        tests/catch.cpp tests/catch.hpp)

set_target_properties(tests PROPERTIES LINKER_LANGUAGE CXX CXX_STANDARD 14)
set_source_files_properties(tests/catchMain.cpp tests/Catch2.h PROPERTIES COMPILE_FLAGS "-std=c++14")
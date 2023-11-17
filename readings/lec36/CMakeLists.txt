cmake_minimum_required(VERSION 3.10)
project(matplot_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O2 ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -O2 -Wall -Wextra -Wconversion -Werror")

find_package(Matplot++ REQUIRED)

add_executable(matplot_test main.cpp)
target_link_libraries(matplot_test PUBLIC Matplot++::matplot)
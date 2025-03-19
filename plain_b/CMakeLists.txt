cmake_minimum_required(VERSION 3.10)

project(Logger)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(Logger Logger.cpp main.cpp)
target_link_libraries(Logger spdlog fmt)

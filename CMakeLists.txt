cmake_minimum_required(VERSION 3.7)
project(u5_labrob)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -static -static-libgcc -static-libstdc++ -pthread")

set(dir ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${dir}/bin")

set(SOURCE_FILES main.cpp maze.cpp maze.h robot.cpp robot.h robot_lefthand.cpp robot_lefthand.h robot_tremaux.h robot_tremaux.cpp robot_gastontarry.cpp robot_gastontarry.h robot_fill_deadend.cpp robot_fill_deadend.h)
add_executable(u5_labrob ${SOURCE_FILES})
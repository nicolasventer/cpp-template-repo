cmake_minimum_required(VERSION 3.14)

add_executable(stdin_math main.cpp)

target_link_libraries(stdin_math PRIVATE math_lib project_warnings)


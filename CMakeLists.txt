cmake_minimum_required(VERSION 3.16)
project(test_task)

set(CMAKE_CXX_STANDARD 17)

add_executable(Matrix "matrix(task1)/main.cpp" "matrix(task1)/matrix.cpp")

add_executable(Money "money(task2)/main.cpp" "money(task2)/money.cpp")
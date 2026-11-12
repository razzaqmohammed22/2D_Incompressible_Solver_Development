
cmake_minimum_required(VERSION 3.16)

project(CFD_Solver)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CFD_Solver
    src/main.cpp
)

target_include_directories(CFD_Solver PRIVATE include)

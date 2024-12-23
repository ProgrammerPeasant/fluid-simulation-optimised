cmake_minimum_required(VERSION 3.27)
project(fluid_simulation_optimised)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(reference)

add_executable(main fluid.cpp)

target_link_libraries(main PRIVATE ThreadPool)


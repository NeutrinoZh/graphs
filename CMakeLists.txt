cmake_minimum_required(VERSION 3.22)

SET (CMAKE_C_COMPILER_WORKS 1)
SET (CMAKE_CXX_COMPILER_WORKS 1)

SET(CMAKE_CXX_FLAGS "-std=c++17")

project(SoulDungeon)

add_executable(main 
    ./src/main.cpp
)

find_package(glm CONFIG REQUIRED)
target_link_libraries(main PRIVATE glm::glm)
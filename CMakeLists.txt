cmake_minimum_required(VERSION 3.22)

SET (CMAKE_C_COMPILER_WORKS 1)
SET (CMAKE_CXX_COMPILER_WORKS 1)

SET(CMAKE_CXX_FLAGS "-std=c++17")

project(SoulDungeon)

add_executable(${PROJECT_NAME}  
    ./src/main.cpp
    ./src/application/application.cpp

    ./src/logger/Logger.cpp
    ./src/logger/LoggerColors.cpp
    ./src/logger/LoggerMessage_1_of_2.cpp
    ./src/logger/LoggerMessage_2_of_2.cpp

    ./src/mvc/window/window-view.cpp
)

include_directories(./src/)

find_package(glm CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm)

find_package(FLTK CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE 
    fltk fltk_gl fltk_forms fltk_images
)
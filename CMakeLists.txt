cmake_minimum_required(VERSION 3.30)
project(GAME)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(RULE)


add_executable(GAME
        src/main.cpp)

target_include_directories(GAME
        PUBLIC
        include
)

target_link_libraries(GAME
        PUBLIC
        RULE
)

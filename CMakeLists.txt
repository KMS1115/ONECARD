cmake_minimum_required(VERSION 3.30)
project(ONECARD)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(RULE)


add_executable(ONECARD
        src/main.cpp)

target_include_directories(ONECARD
        PUBLIC
        include
)

target_link_libraries(ONECARD
        PUBLIC
        RULE
)

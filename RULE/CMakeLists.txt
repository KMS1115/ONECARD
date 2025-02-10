cmake_minimum_required(VERSION 3.30)
project(RULE)

add_library(RULE STATIC
        src/Card.cpp
        src/Deck.cpp
        src/Game.cpp
        src/Player.cpp
)
target_include_directories(RULE
        PUBLIC
        include
)


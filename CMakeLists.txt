cmake_minimum_required(VERSION 3.28)
project(pong_game)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.1.0
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM
)

FetchContent_MakeAvailable(SFML)

add_executable(pong_game src/main.cpp)

target_include_directories(pong_game
    PRIVATE
        include
)

target_link_libraries(pong_game PRIVATE SFML::Graphics)

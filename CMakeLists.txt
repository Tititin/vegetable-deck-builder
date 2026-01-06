cmake_minimum_required(VERSION 3.20)
project(VegetableDeckBuilder LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# SFML 3 : composants et targets
find_package(SFML CONFIG REQUIRED COMPONENTS Graphics Window System)

add_executable(game src/main.cpp)

# Utiliser les targets CMake exportées
target_link_libraries(game PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)

cmake_minimum_required(VERSION 3.20)
project(VegetableDeckBuilder LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ASSETS_DIR ${CMAKE_SOURCE_DIR}/assets)


# SFML 3 : composants et targets
find_package(SFML CONFIG REQUIRED COMPONENTS Graphics Window System)

add_executable(game 
    src/main.cpp
    src/Card.cpp
    src/Potager.cpp
    src/TextureManager.cpp)

add_custom_command(
    TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${ASSETS_DIR}
            $<TARGET_FILE_DIR:game>/assets
)

# Utiliser les targets CMake exportées
target_link_libraries(game PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)

cmake_minimum_required(VERSION 3.14)
project(R-Type_Client)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_definitions(-DBOOST_BIND_GLOBAL_PLACEHOLDERS)

# Local includes if needed
include_directories(
    ${CMAKE_SOURCE_DIR}/R-Type/include
    ${CMAKE_SOURCE_DIR}/R-Type/include/Entity
    ${CMAKE_SOURCE_DIR}/ECS
    ${CMAKE_SOURCE_DIR}/ECS/systems
    ${CMAKE_SOURCE_DIR}/ECS/components
)

# The Client library sources
set(CLIENT_SOURCES
    src/Client.cpp
    include/Client.hpp
)

add_library(ClientLib ${CLIENT_SOURCES})

# Link with R-Type if it uses game logic, Boost if needed, SFML if needed, ECSLib, etc.
target_link_libraries(ClientLib
    R-Type
    Boost::Boost
    SFML::SFML
    ECSLib
)

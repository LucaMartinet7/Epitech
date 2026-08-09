cmake_minimum_required(VERSION 3.14)
project(Network)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_definitions(-DBOOST_BIND_GLOBAL_PLACEHOLDERS)

include_directories(
    ${CMAKE_SOURCE_DIR}/Server/include
    ${CMAKE_SOURCE_DIR}/R-Type/include
    ${CMAKE_SOURCE_DIR}/R-Type/include/Entity
    ${CMAKE_SOURCE_DIR}/ECS
    ${CMAKE_SOURCE_DIR}/ECS/systems
    ${CMAKE_SOURCE_DIR}/ECS/components
)

# Network sources
set(NETWORK_SOURCES
    src/PacketHandler.cpp
    src/Packet.cpp
)

set(NETWORK_HEADERS
    include/PacketHandler.hpp
    include/Data.hpp
    include/Packet.hpp
    include/PacketType.hpp
    include/ThreadSafeQueue.hpp
)

# Create Network library
add_library(NetworkLib ${NETWORK_SOURCES} ${NETWORK_HEADERS})

# Include directories
target_include_directories(NetworkLib PUBLIC include)

# Link dependencies
target_link_libraries(NetworkLib
    Boost::Boost
    SFML::SFML
)

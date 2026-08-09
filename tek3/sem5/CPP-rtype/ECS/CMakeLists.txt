# ECS/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(ECS)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Define ECS sources
set(ECS_SOURCES
    systems/PositionSystem.hpp
    systems/CollisionSystem.hpp
    systems/ControlSystem.hpp
    systems/DrawSystem.hpp
    systems/ProjectileSystem.hpp
    components/Position.hpp
    components/Velocity.hpp
    components/Drawable.hpp
    components/Controllable.hpp
    components/Collidable.hpp
    components/Projectile.hpp
        Registry.hpp
    components/SparseArray.hpp
    components/Entity.hpp
)

# Add ECS library
add_library(ECSLib INTERFACE)

# Include directories for the ECS library
target_include_directories(ECSLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
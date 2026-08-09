cmake_minimum_required(VERSION 3.14)
project(R-Type)

# --- C++17 setup ---
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CLIENT_BINARY "r-type_client")
set(SERVER_BINARY "r-type_server")

# If you need to define Boost placeholders globally
add_definitions(-DBOOST_BIND_GLOBAL_PLACEHOLDERS)

include_directories(
    ${CMAKE_SOURCE_DIR}/R-Type/include
    ${CMAKE_SOURCE_DIR}/R-Type/include/Entity
    ${CMAKE_SOURCE_DIR}/Network
    ${CMAKE_SOURCE_DIR}/Network/include
    ${CMAKE_SOURCE_DIR}/Server/
    ${CMAKE_SOURCE_DIR}/Server/include/
    ${CMAKE_SOURCE_DIR}/ECS/
    ${CMAKE_SOURCE_DIR}/ECS/systems/
    ${CMAKE_SOURCE_DIR}/ECS/components/
    ${CMAKE_SOURCE_DIR}/Server/Errors/
    ${CMAKE_SOURCE_DIR}/Client/include/

)

# --- Subdirectories ---
add_subdirectory(ECS)
add_subdirectory(Network)
add_subdirectory(Client)
add_subdirectory(Server)
add_subdirectory(R-Type)

# --- FetchContent setup ---
include(FetchContent)

# Put all third-party libs into build/3rdparty
set(FETCHCONTENT_BASE_DIR "${CMAKE_CURRENT_BINARY_DIR}/3rdparty"
    CACHE STRING "Download directory for 3rd party"
    FORCE
)

# Fetch Boost
FetchContent_Declare(
    Boost
    URL https://github.com/boostorg/boost/releases/download/boost-1.83.0/boost-1.83.0.zip
    DOWNLOAD_NAME boost_1_83_0.zip
    DOWNLOAD_NO_PROGRESS TRUE
)
# Which Boost sub-libraries to build (adjust as needed)
set(BOOST_INCLUDE_LIBRARIES
    asio
    filesystem
    system
    iostreams
)
FetchContent_MakeAvailable(Boost)

# Create a meta-target called Boost::Boost bundling sub-libs
add_library(Boost INTERFACE)
add_library(Boost::Boost ALIAS Boost)
target_link_libraries(Boost INTERFACE
    Boost::asio
    Boost::filesystem
    Boost::system
    Boost::date_time
    Boost::iostreams
)

# Fetch SFML
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.0
)
# SFML build options
set(SFML_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_AUDIO ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(SFML)

# Create a meta-target called SFML::SFML bundling sfml libs
add_library(SFML INTERFACE)
add_library(SFML::SFML ALIAS SFML)
target_link_libraries(SFML INTERFACE
    sfml-system
    sfml-window
    sfml-graphics
    sfml-audio
)


# Add executables for client/server "main.cpp"
# Client main
add_executable(r-type_client Client/main.cpp)
target_link_libraries(r-type_client
    ClientLib
    R-Type
    Boost::Boost
    SFML::SFML
)

# Server main
add_executable(r-type_server Server/main.cpp)
target_link_libraries(r-type_server
    ServerLib
    R-Type
    Boost::Boost
    SFML::SFML
)
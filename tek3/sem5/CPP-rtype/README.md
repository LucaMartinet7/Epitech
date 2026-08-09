# R-Type Project

## Overview
The R-Type Project is a multiplayer 2D game inspired by classic arcade shoot-'em-ups. It is designed with a modular architecture, separating the server, client, and game engine to ensure scalability and maintainability. The project leverages modern C++ standards, the Entity-Component-System (ECS) architecture, and robust networking protocols.

## Features
- **Multiplayer**: Real-time interactions between players through a centralized server.
- **Game Engine**: A modular and flexible Entity-Component-System (ECS) framework for game logic and rendering.
- **Protocol-Driven**: A custom-designed protocol ensures smooth and efficient communication.
- **Cross-Platform**: Works on Linux and Windows.
- **Asynchronous Networking**: High-performance non-blocking communication using Boost.Asio.
- **2D Rendering Pipeline**: Built with SFML, the engine supports real-time rendering of game entities and environments.

## Project Components

### 1. Server
The R-Type Server is responsible for:
- Managing client connections, game sessions, and player data.
- Broadcasting game state updates to clients.
- Ensuring synchronization across all players.

#### Key Features:
- Asynchronous UDP communication via Boost.Asio.
- Multi-threaded architecture with a thread-safe packet processing queue.
- Modular handling of game events like player movement, game start, and game end.

#### Key Files:
- `Server.cpp`: Core logic for managing the server.
- `PacketHandler.cpp`: Processes game-specific packets.
- `ThreadSafeQueue.hpp`: Ensures concurrency in packet processing.

### 2. Client
The R-Type Client acts as the graphical interface and gameplay front-end. It:
- Communicates with the server to send player inputs and receive game updates.
- Renders the game state using the SFML library.
- Implements a local ECS model to handle gameplay logic.

#### Key Features:
- Asynchronous communication with the server.
- Real-time rendering of player and enemy entities.
- Input handling and event-driven gameplay updates.

#### Key Files:
- `Client.cpp`: Core client logic.

### 3. Game Engine
The R-Type Game Engine powers the client and adheres to the Entity-Component-System (ECS) design. It is responsible for managing:
- **Entities**: Players, enemies, projectiles, etc.
- **Components**: Attributes like position, velocity, and graphics.
- **Systems**: Logic for updating positions, detecting collisions, and rendering graphics.

#### Key Features:
- Entity-Component-System (ECS): Modular and scalable architecture.
- Collision detection for player and enemy interactions.
- Easily extendable with new entities and systems.

#### Key Files:
- `Registry.hpp`: Manages entity and component lifecycles.
- `CollisionSystem.hpp`: Handles interactions between collidable entities.
- `PositionSystem.hpp`: Updates entity positions based on velocity.

### 4. Protocol
The R-Type Protocol facilitates communication between the server and clients. It:
- Categorizes packets into types (e.g., `PLAYER_MOVED`, `GAME_START`).
- Structures payloads for efficient serialization and parsing.
- Supports robust error handling and client synchronization.

#### Packet Structure:
- **Type (PacketType)**: Specifies the action (e.g., `REQCONNECT`).
- **Client ID**: Identifies the sender or recipient.
- **Payload**: Contains action-specific data.

#### Key Files:
- `protocol.md`: Detailed protocol documentation.

## Architecture

### Entity-Component-System (ECS)
The ECS architecture divides game logic into:
- **Entities**: Game objects with unique IDs (e.g., player, enemy).
- **Components**: Data associated with entities (e.g., position, velocity).
- **Systems**: Logic that processes specific components (e.g., movement, rendering).

This design ensures modularity, scalability, and ease of maintenance.

#### Example Components:
- **Position**: Tracks the 2D coordinates of an entity.
- **Velocity**: Stores the speed and direction of movement.
- **Drawable**: Indicates entities that need rendering.

#### Example Systems:
- **ControlSystem**: Updates velocities based on user input.
- **CollisionSystem**: Detects and resolves collisions.
- **DrawSystem**: Renders entities on the screen.

## Technical Details

### Networking
- Boost.Asio handles asynchronous UDP communication.
- The server uses a reactor pattern for non-blocking event processing.

### Rendering
- SFML powers 2D rendering, window management, and input handling.

### Error Handling
- Malformed or unauthorized packets trigger disconnections.
- Logs capture networking and gameplay issues for debugging.

## Getting Started

### Requirements
- C++17 or newer.
- GCC 9.4+, Clang 10+, or MSVC.


## Build Instructions

## Clone the Repository
```bash
git clone https://github.com/LucaMartinet7/R-Type.git
```

## Install Dependencies

### Linux
Using the file named `install_dependencies.sh`.
Make the script executable and run it:
```bash
chmod +x install_dependencies.sh
./install_dependencies.sh
```

### macOS
Use Homebrew to install the required dependencies:
```bash
brew install cmake g++
```
For Docker installation, visit: [Docker for macOS](https://docs.docker.com/docker-for-mac/install/).

### Windows
Use your preferred package manager to install:
- Visual Studio with C++ build tools
- [CMake](https://cmake.org/download/)
- [Docker Desktop](https://www.docker.com/products/docker-desktop/).

## Docker Build

To build the Docker image:
```bash
docker build --no-cache -t r-type-server .
```

Run the container to test:
```bash
docker run -p 8080:8080 r-type-server
```

## Manual Build

If you prefer to build the project manually, follow these steps:
```bash
mkdir build
cd build
cmake ..
make
```

## Run the Server and Client

Start the server:
```bash
./r-type_server <port>
```

Start the client:
```bash
./r-type_client <host> <server-port> <client-port>
```



## Contribution Guidelines
- Follow the existing coding standards.
- Use meaningful commit messages.
- Discuss significant changes via issues before creating pull requests.

## Contact
- Email: etienne.namur@epitech.eu
- Email: luca.martinet@epitech.eu
- Email: noe.kurata@epitech.eu
- Email: loup.marquez@epitech.eu

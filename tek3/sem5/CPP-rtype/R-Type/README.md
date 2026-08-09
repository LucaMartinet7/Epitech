## README: R-Type Game Engine

---

### Overview

The **R-Type Game Engine** is a 2D game engine designed to support the development of games inspired by classic shoot-'em-ups. The engine provides a robust foundation for managing entities, components, and systems, adhering to the Entity-Component-System (ECS) architecture. With features like collision detection, rendering, and a modular design, developers can easily build engaging 2D games.

---

### Key Concepts

- **Entity-Component-System (ECS):**  
  The engine employs ECS for a modular and efficient way to handle game entities. This separation allows for flexibility in defining entity behaviors through components and systems.

- **Core Features:**  
  - Player and enemy entities with unique behaviors.  
  - Systems for movement, control, projectiles, and collision detection.  
  - Customizable menus for game start and game over screens.  
  - A rendering pipeline leveraging the SFML library.

---

### Project Structure

- **`Game.hpp` and `Game.cpp`:**  
  The main game class that manages the application lifecycle, including event handling, updates, and rendering.

- **Entity Classes:**  
  - **`Player.hpp`**: Represents the player entity, providing movement and shooting functionality.  
  - **`Enemy.hpp`**: Represents enemy entities with AI-driven behaviors.  
  - **`Bullet.hpp`**: Represents projectiles fired by players or enemies.

- **Component Classes:**  
  - **`Position`**: Tracks the spatial position of entities.  
  - **`Velocity`**: Defines movement speeds.  
  - **`Drawable`**: Flags entities as renderable.  
  - **`Collidable`**: Marks entities that participate in collision detection.  
  - **`Controllable`**: Enables player-driven control.  
  - **`Projectile`**: Tags projectiles with unique properties.

- **System Classes:**  
  - **`PositionSystem`**: Updates entity positions based on velocity.  
  - **`ControlSystem`**: Handles player inputs and interactions.  
  - **`ProjectileSystem`**: Manages projectile behaviors.  
  - **`CollisionSystem`**: Detects and resolves collisions.  
  - **`DrawSystem`**: Renders entities on the screen.

- **UI Classes:**  
  - **`Menu.hpp`**: Manages the in-game menu, including start and game-over screens.

- **`main.cpp`:**  
  Entry point for the application. Instantiates and runs the `Game` class.

---

### Setup Instructions

#### Requirements

- **C++17 or newer.**
- **SFML 2.5.1 or newer.** (for rendering and input handling)

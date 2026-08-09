## README: R-Type ECS
# Entity Component System (ECS) Documentation

## Overview  
The **Entity Component System (ECS)** is a powerful architectural design pattern widely used in game development. It emphasizes **composition over inheritance**, enabling greater flexibility, modularity, and reusability.  

### Key Concepts:  
- **Entities**: Identified by unique IDs, they represent game objects.  
- **Components**: Store data and represent attributes or properties of entities.  
- **Systems**: Contain logic that operates on entities with specific components.  

This approach cleanly separates **data** (components) from **logic** (systems), making it easier to extend and maintain your codebase.

---

## Project Structure  

### Components  
Components are simple data structures that store an entity's state. Each type of component is stored in a sparse array for efficient management.

| **Component** | **Description** |
|---------------|------------------|
| **Position**  | Stores the 2D position of an entity. |
| **Velocity**  | Stores the velocity of an entity. |
| **Drawable**  | Stores the drawable shape of an entity. |
| **Controllable** | Marks an entity as controllable by the user. |
| **Projectile** | (In Development) Stores the properties of a projectile entity. |

---

### Systems  
Systems encapsulate the logic for manipulating components. They operate on entities that possess a specific combination of components.  

| **System** | **Functionality** |
|------------|--------------------|
| **Position System** | Updates the position of entities based on their velocity. |
| **Control System**  | Updates the velocity of controllable entities based on user input. |
| **Draw System**     | Renders drawable entities on the screen. |
| **Projectile System** | (In Development) Manages the behavior and lifecycle of projectile entities. |

---

### Registry  
The **Registry** class is the heart of the ECS. It handles:  
- Entity creation and deletion.  
- Component management (adding, updating, and removing).  
- System execution based on registered entities.  

**Key File**: `Registry.h`

---

## Conclusion  
This ECS implementation delivers a **modular**, **flexible**, and **scalable** architecture tailored for game development. By decoupling data from logic, you can easily add, modify, or extend game features without introducing unnecessary complexity.  

Dive in and enjoy building your next game with the power of ECS! 🎮
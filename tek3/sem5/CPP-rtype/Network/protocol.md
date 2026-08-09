# R-Type Protocol

## Def
This document defines the communication protocol between the server and clients in **R-Type**. The server maintains the game state, sending updates to clients, while clients relay player inputs and react to server commands. The `PacketType` enum categorizes packets for streamlined communication.

---

## Table of Contents
1. [Packet Structure](#packet-structure)
2. [Connection](#connection)
3. [Gameplay Flow](#gameplay-flow)
    - [Creating a Game](#creating-a-game)
    - [Joining a Game](#joining-a-game)
4. [Gameplay Communication](#gameplay-communication)
    - [Server-to-Client Packets](#server-to-client-packets)
    - [Client-to-Server Packets](#client-to-server-packets)
5. [Payload Details](#payload-details)
6. [Error Handling](#error-handling)

---

## Packet Structure
Each packet exchanged between the server and clients consists of:
- **Type (`PacketType`)**: Specifies the packet category (1 byte).
- **Entity_ID**: Identifies the Entity (Player/Enemy/Image etc).
- **Positions**: x and y positions or "-1" if not relevant.

---

## Connection
1. The Server listens on a specified port (e.g., `./r-type_server 8080`).
2. Clients connect to the Server at the designated endpoint and port (e.g., `./r-type_client localhost 8080 8081`).
3. Upon connection, the Client sends a `REQCONNECT` packet to confirm.
4. The Server responds with a `GAME_STARTED` or `GAME_NOT_STARTED` packet.

---

## Gameplay Flow

### Creating a Game
1. Client sends a `GAME_START` packet to create a new game instance.
2. Server responds with a `GAME_STARTED` packet.
3. Clients receive the `GAME_STARTED` packet and begin gameplay.
---

### Joining a Game
1. All clients connected to the server receive a `GAME_START` packet.

---

## Gameplay Communication

### Server-to-Client Packets
1. **Game State Updates**
   - **Packet Type**: `CHANGE`
   - **Payload**: Serialized game state (e.g., entity positions).
2. **Player Events**
   - **Packet Type**:
     - `CHANGE` for movement.
     - `PLAYER_SHOOT` for firing.
     - `PLAYER_SCORE` for score updates.
     - `PLAYER_DEAD` for destruction.
     - `PLAYER_HIT` for death animation.
   - **Payload**: Relevant player data.
3. **Enemy Events**
   - **Packet Type**:
     - `CREATE_ENEMY` for new Enemy creation.
     - `CREATE_BOSS` for new Boss creation.
     - `CHANGE` for movement.
     - `DELETE` for destruction.
   - **Payload**: Relevant enemy data.
4. **Game End**
   - **Packet Type**:
      - `GAME_END`
      - `GAME_START`

---

### Client-to-Server Packets
1. **Server Checks**
   - **Packet Type**:
      - `REQCONNECT` for creation.
      - `DISCONNECTED` for destruction.
2. **Player Actions**
   - **Packet Type**:
     - `PLAYER_RIGHT/LEFT/UP/DOWN` for directional input.
     - `PLAYER_SHOOT` for firing.
3. **Game Actions**
   - **Packet Type**:
     - `OPEN_MENU` for menu interactions.
     - `MOUSE_CLICK` for mouse events.

---

## Payload Details

| **Packet Type**      | **Payload Format**                                         | **Description**                                |
|-----------------------|-----------------------------------------------------------|------------------------------------------------|
| `REQCONNECT`          | `None`                                                    | Sent by the Client to confirm connection.      |
| `DISCONNECTED`        | `None`                                                    | Client disconnects from the server.            |
| `GAME_START`          | `None`                                                    | Start a new game.                              |
| `GAME_NOT_STARTED`    | `None`                                                    | Game not started yet.                          |
| `GAME_STARTED`        | `None`                                                    | Game has started.                              |
| `DELETE`              | `[ID]`                                                    | Delete the specified entity.                   |
| `GAME_END`            | `[RESULT]`                                                | End of game with the outcome.                  |
| `PLAYER_SHOOT`        | `[ID, X, Y]`                                              | Player fires a projectile.                     |
| `CREATE_ENEMY`        | `[ID, X, Y]`                                              | Create a new enemy at the specified position.  |
| `CREATE_BOSS`         | `[ID, X, Y]`                                              | Create a new boss at the specified position.   |
| `CREATE_PLAYER`       | `[ID, X, Y]`                                              | Create a new player at the specified position. |
| `CREATE_BULLET`       | `[ID, X, Y]`                                              | Create a new bullet at the specified position. |
| `BACKGROUND`          | `[ID, X, Y]`                                              | Update the background.                         |
| `CREATE_POWERUP`      | `[ID, X, Y]`                                              | Create a new power-up.                         |
| `CHANGE`              | `[ID, X, Y]`                                              | Change the specified entity's position.        |
| `PLAYER_[DIRECTION]`  | `[ACTION;ID;X;Y]`                                         | Move specific Entity to next position.         |

---

## Error Handling
1. Malformed or unauthorized packets result in a `[PacketHandler] Received unknown packet type.` response.

---

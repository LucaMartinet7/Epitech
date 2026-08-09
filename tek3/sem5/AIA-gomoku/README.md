# Gomoku

Gomoku is a board game. This project aims to create an AI capable of winning this game against any user.

It's part of the Advanced Artificial Intelligence module of Epitech's tek3.

## Before continuing...

This project is an EPITECH project. If you are an EPITECH student, please respect academic integrity and avoid using this code for your assignments. Using this code may result in a grade of -42. If you're not an EPITECH student, welcome! Feel free to explore and use this project.

### Prerequisites

To use this project, you'll need `Python 3` installed on your machine. It is also recommended to have `make` installed.

### Build

To build and run the project, follow these steps:

1. Build the project using `make`:
    ```sh
    make
    ```

2. Run the game:
    ```sh
    ./pbrain-gomoku-ai
    ```

3. Alternatively, you can run the game using Python:
    ```sh
    python3 pbrain-gomoku-ai
    ```
    or
    ```sh
    python3 main.py
    ```

## Communication Protocol

### Mandatory Commands

- **START [size]**
  - Initializes the board with the given size.
  - Example:
    ```sh
    START 20
    ```

- **TURN [X],[Y]**
  - Processes the opponent's move and makes the bot's move.
  - Example:
    ```sh
    TURN 10,10
    ```

- **BEGIN**
  - Starts the game and makes the first move.
  - Example:
    ```sh
    BEGIN
    ```

- **BOARD**
  - Sets up the board state from the input.
  - Example:
    ```sh
    BOARD
    10,10,1
    10,11,2
    11,11,1
    9,10,2
    DONE
    ```

- **INFO [key] [value]**
  - Sends information to the brain.
  - Example:
    ```sh
    INFO timeout_turn 10000
    ```

- **END**
  - Terminates the game.
  - Example:
    ```sh
    END
    ```

- **ABOUT**
  - Provides information about the bot.
  - Example:
    ```sh
    ABOUT
    ```

### Optional Commands (Not done)

- **RECTSTART [width],[height]**
  - Initializes a rectangular board.
  - Example:
    ```sh
    RECTSTART 30,20
    ```

- **RESTART**
  - Restarts the game with the same board size.
  - Example:
    ```sh
    RESTART
    ```

- **TAKEBACK [X],[Y]**
  - Undoes the last move.
  - Example:
    ```sh
    TAKEBACK 9,10
    ```

- **PLAY [X],[Y]**
  - Imposes a move to the brain.
  - Example:
    ```sh
    PLAY 12,10
    ```

- **SWAP2BOARD**
  - Deals with the opening stage of Swap2 rule.
  - Example:
    ```sh
    SWAP2BOARD
    DONE
    ```

## Documentation

Each function is thoroughly documented with detailed explanations of its purpose and functionality.

# Authors

**Luca Martinet** - [lucamartinet7](https://github.com/lucamartinet7)

**Noe Kurata** - [nkurata](https://github.com/nkurata)
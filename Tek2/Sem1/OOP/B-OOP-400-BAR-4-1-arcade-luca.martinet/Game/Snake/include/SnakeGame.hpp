/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** SnakeGame
*/

#include <chrono>
#include <deque>

#include "IArcade.hpp"
#include "AObject.hpp"

#ifndef _SNAKEGAME_HPP
    #define _SNAKEGAME_HPP

#define MAP_SIZE_X       30
#define MAP_SIZE_Y       20

#define SNAKE_SPAWN_LEN 4
#define SNAKE_COLOR     {113, 18, 255}

#define APPLE_POS       {rand() % (MAP_SIZE_X - 3) + 1, rand() % (MAP_SIZE_Y - 3) + 1}
#define APPLE_COLOR     {255, 0, 44}

#define WALL_COLOR      {99, 115, 0}
#define OBJECT_SIZE     {1, 1}

#define COOLDOWN        150

namespace arcade {
    enum class Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        PAUSE
    };
    class SnakeGame : public IGameModule{
        public:
            SnakeGame();
            void manageEvent(std::vector<std::unique_ptr<IEvent>> const &) override;
            void iterate(void) override;
            data_t const &getMap(void) const override;

            void createMap(void);
            void changeApplePos(void);
            void updateMap(std::array<int, 2> pos, std::array<int, 3> RGB);
            void restartGame(void);
            void updateSnake(std::array<int, 2> pos, std::array<int, 3> RGB);
            void removeOldSnakeSegments(void);
            void setSnakeHeadAttributes(std::unique_ptr<AObject> &obj, std::array<int, 3> RGB);
            void setSnakeBodyAttributes(std::unique_ptr<arcade::AObject>& obj, std::array<int, 3> RGB, Direction snakeDir);
            void setSnakeTailAttributes(std::unique_ptr<arcade::AObject>& obj, std::array<int, 3> RGB, Direction snakeDir);
            void updateApple(std::array<int, 2> pos, std::array<int, 3> RGB);
            ~SnakeGame();
        private:
            data_t _map;
            std::deque<std::array<int, 2>> _snakePositions;
            std::deque<Direction> _snakeDirections;
            size_t _snakeLength;
            std::array<int, 2> _snakePos;
            std::array<int, 2> _applePos;
            Direction _snakeDir;
            size_t _it;
            std::chrono::_V2::system_clock::time_point _lastIteranceTime;
            int _boost; //TODO : Implement boost
    };
}

#endif /* !_SNAKEGAME_HPP */

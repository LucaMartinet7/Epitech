/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** entrypoint
*/

#include <memory>

#include "SnakeGame.hpp"
#include "AObject.hpp"
#include "AEvent.hpp"

extern "C" std::unique_ptr<arcade::IGameModule> entryPoint()
{
    return std::make_unique<arcade::SnakeGame>();
}

arcade::SnakeGame::SnakeGame()
{
    srand(time(NULL));
    createMap();
    _snakeLength = SNAKE_SPAWN_LEN;
    _snakePos = {(MAP_SIZE_X - 2) / 2, (MAP_SIZE_Y - 2) / 2};
    _applePos = APPLE_POS;
    _it = 0;
    _lastIteranceTime = std::chrono::system_clock::now();
    _snakeDir = static_cast<arcade::Direction>(rand() % 4);
}

arcade::SnakeGame::~SnakeGame()
{
    _map.objects.clear();
}

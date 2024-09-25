/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** game
*/

#include "SnakeGame.hpp"
#include "AObject.hpp"

void arcade::SnakeGame::iterate(void)
{
    auto currentTime = std::chrono::system_clock::now();

    if (std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - _lastIteranceTime).count() < COOLDOWN)
        return;
    _lastIteranceTime = currentTime;
    switch (_snakeDir)  {
        case arcade::Direction::UP:
            _snakePos[1] -= 1;
            break;
        case arcade::Direction::DOWN:
            _snakePos[1] += 1;
            break;
        case arcade::Direction::LEFT:
            _snakePos[0] -= 1;
            break;
        case arcade::Direction::RIGHT:
            _snakePos[0] += 1;
            break;
        default:
            return;
    }
    if (_snakePos == _applePos) {
        _snakeLength += 1;
        changeApplePos();
    }

    updateMap(_applePos, APPLE_COLOR);
    updateMap(_snakePos, SNAKE_COLOR);
    _it++;

    for (size_t i = 0; i < _map.objects.size() - 1; i++) {
        auto &obj = _map.objects[i];
        if (obj && obj->getPos() == _snakePos && (obj->getRGB() == std::array<int, 3>WALL_COLOR || obj->getRGB() == std::array<int, 3>SNAKE_COLOR) && _it > 3) {
            restartGame();
        }
    }
}

void arcade::SnakeGame::restartGame(void)
{
    _map.objects.clear();
    createMap();
    _snakeLength = SNAKE_SPAWN_LEN;
    _snakePos = {(MAP_SIZE_X - 2) / 2, (MAP_SIZE_Y - 2) / 2};
    _applePos = APPLE_POS;
    _it = 0;
    _lastIteranceTime = std::chrono::system_clock::now();
    _snakeDir = arcade::Direction::PAUSE;
    _snakePositions.clear();
    _snakeDirections.clear();
    updateMap(_snakePos, SNAKE_COLOR);
}

void arcade::SnakeGame::changeApplePos(void)
{
    std::array<int, 2> lastPos = _applePos;
    std::array<int, 2> newPos = {APPLE_POS};

    if (lastPos == newPos) {
        newPos[0] = (newPos[0] + 1) % 24;
        newPos[1] = (newPos[1] + 1) % 19;
    }
    for (const auto& obj : _map.objects) {
        if (obj && obj->getPos() == newPos && obj->getRGB() == std::array<int, 3>SNAKE_COLOR) {
            changeApplePos();
            return;
        }
    }
    _applePos = newPos;
}

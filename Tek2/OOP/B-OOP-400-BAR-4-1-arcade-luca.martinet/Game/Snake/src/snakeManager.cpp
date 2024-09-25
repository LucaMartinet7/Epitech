/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** snakeManager
*/

#include <algorithm>

#include "SnakeGame.hpp"
#include "AObject.hpp"

void arcade::SnakeGame::updateSnake(std::array<int, 2> pos, std::array<int, 3> RGB)
{
    _snakePositions.push_back(pos);
    _snakeDirections.push_back(_snakeDir);

    if (_snakePositions.size() > _snakeLength) {
        _snakePositions.pop_front();
        _snakeDirections.pop_front();
        removeOldSnakeSegments();
    }

    for (size_t i = 0; i < _snakePositions.size(); ++i) {
        auto &snakePos = _snakePositions[i];
        auto &snakeDir = _snakeDirections[i];
        std::unique_ptr<arcade::AObject> obj = std::make_unique<arcade::AObject>();
        obj->setPos(snakePos);
        obj->setSize(OBJECT_SIZE);

        if (snakePos == _snakePositions.back()) {
            setSnakeHeadAttributes(obj, RGB);
        } else if (snakePos == _snakePositions.front()) {
            setSnakeTailAttributes(obj, RGB, snakeDir);
        } else {
            setSnakeBodyAttributes(obj, RGB, snakeDir);
        }

        obj->setAscii('O');
        obj->setType(arcade::Type::Graphic);
        _map.objects.push_back(std::move(obj));
    }
}

void arcade::SnakeGame::removeOldSnakeSegments()
{
    _map.objects.erase(std::remove_if(_map.objects.begin(), _map.objects.end(),
        [&](const std::unique_ptr<arcade::IObject>& obj) {
            auto aObj = dynamic_cast<arcade::AObject*>(obj.get());
            return aObj && (aObj->getRGB() == std::array<int, 3>(SNAKE_COLOR) || aObj->getRGB() == std::array<int, 3>({255, 0, 0}) || aObj->getRGB() == std::array<int, 3>({0, 255, 0}));
        }), _map.objects.end());
}

void arcade::SnakeGame::setSnakeHeadAttributes(std::unique_ptr<arcade::AObject>& obj, std::array<int, 3> RGB)
{
    obj->setRGB(RGB);
    if (_snakeDir == Direction::UP)
        obj->setAsset("Assets/snake/snakeHeadUp.png");
    else if (_snakeDir == Direction::DOWN)
        obj->setAsset("Assets/snake/snakeHeadDown.png");
    else if (_snakeDir == Direction::LEFT)
        obj->setAsset("Assets/snake/snakeHeadLeft.png");
    else if (_snakeDir == Direction::RIGHT)
        obj->setAsset("Assets/snake/snakeHeadRight.png");
}

void arcade::SnakeGame::setSnakeTailAttributes(std::unique_ptr<arcade::AObject>& obj, std::array<int, 3> RGB, Direction snakeDir)
{
    obj->setRGB(RGB);
    if (snakeDir == Direction::UP)
        obj->setAsset("Assets/snake/snakeTailUp.png");
    else if (snakeDir == Direction::DOWN)
        obj->setAsset("Assets/snake/snakeTailDown.png");
    else if (snakeDir == Direction::LEFT)
        obj->setAsset("Assets/snake/snakeTailLeft.png");
    else if (snakeDir == Direction::RIGHT)
        obj->setAsset("Assets/snake/snakeTailRight.png");
}

void arcade::SnakeGame::setSnakeBodyAttributes(std::unique_ptr<arcade::AObject>& obj, std::array<int, 3> RGB, Direction snakeDir)
{
    obj->setRGB(RGB);
    if (snakeDir == Direction::UP || snakeDir == Direction::DOWN)
        obj->setAsset("Assets/snake/snakeBodyVertical.png");
    else if (snakeDir == Direction::LEFT || snakeDir == Direction::RIGHT)
        obj->setAsset("Assets/snake/snakeBodyHorizontal.png");
}

void arcade::SnakeGame::updateApple(std::array<int, 2> pos, std::array<int, 3> RGB)
{
    std::unique_ptr<arcade::AObject> obj = std::make_unique<arcade::AObject>();
    obj->setPos(pos);
    obj->setSize(OBJECT_SIZE);
    obj->setRGB(RGB);
    obj->setAscii('A');
    obj->setType(arcade::Type::Graphic);
    obj->setAsset("Assets/snake/apple.png");

    if (RGB == std::array<int, 3>(APPLE_COLOR)) {
        if (_it > 0)
            _map.objects.erase(_map.objects.begin());
        _map.objects.insert(_map.objects.begin(), std::move(obj));
    }
}

/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** mapUtils
*/

#include "SnakeGame.hpp"
#include "AObject.hpp"

void arcade::SnakeGame::createMap(void)
{
    _map.size = std::make_pair(MAP_SIZE_X, MAP_SIZE_Y);
    for (int i = 0; i < MAP_SIZE_X; i++) {
        for (int j = 0; j < MAP_SIZE_Y; j++) {
            if (i == 0 || i == MAP_SIZE_X - 1 || j == 0 || j == MAP_SIZE_Y - 1) {
                std::unique_ptr<arcade::AObject> obj = std::make_unique<arcade::AObject>();
                obj->setPos({i, j});
                obj->setSize(OBJECT_SIZE);
                obj->setRGB(WALL_COLOR);
                obj->setAscii('#');
                obj->setAsset("Assets/snake/wall.png");
                obj->setType(arcade::Type::Graphic);
                _map.objects.push_back(std::move(obj));
            }
        }
    }
}

void arcade::SnakeGame::updateMap(std::array<int, 2> pos, std::array<int, 3> RGB)
{
    if (RGB == std::array<int, 3>(SNAKE_COLOR)) {
        updateSnake(pos, RGB);
    } else {
        updateApple(pos, RGB);
    }
}

arcade::data_t const &arcade::SnakeGame::getMap(void) const
{
    return _map;
}

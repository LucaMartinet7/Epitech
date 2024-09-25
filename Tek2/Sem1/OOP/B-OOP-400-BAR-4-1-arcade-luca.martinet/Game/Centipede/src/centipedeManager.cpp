/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** CentipedeManager
*/

#include <algorithm>
#include <cmath>

#include "CentipedeGame.hpp"
#include "AObject.hpp"

void arcade::CentipedeGame::updateCentipede(std::vector<std::array<int, 2>> pos, std::array<int, 3> RGB)
{
    auto it = _map.objects.begin() + 2;
    while (it != _map.objects.end()) {
        if ((*it)->getAscii() == 'C')
            it = _map.objects.erase(it);
        else
            ++it;
    }
    for (int i = 0; i < 8; ++i) {
        std::unique_ptr<arcade::AObject> obj = std::make_unique<arcade::AObject>();
        obj->setPos(pos[i]);
        obj->setSize(OBJECT_SIZE);
        obj->setRGB(RGB);
        obj->setAscii('C');
        obj->setAsset("Assets/snake/snakeHeadDown.png");
        obj->setType(arcade::Type::Graphic);
        _map.objects.insert(_map.objects.begin() + 2 + i, std::move(obj));
    }
}

void arcade::CentipedeGame::updatePlayer(std::array<int, 2> pos, std::array<int, 3> RGB)
{
    std::unique_ptr<arcade::AObject> obj = std::make_unique<arcade::AObject>();
    obj->setPos(pos);
    obj->setSize(OBJECT_SIZE);
    obj->setRGB(RGB);
    obj->setAscii('P');
    obj->setAsset("Assets/centipede/player.png");
    obj->setType(arcade::Type::Graphic);
    if (_it > 0)
        _map.objects.erase(_map.objects.begin());
    _map.objects.insert(_map.objects.begin(), std::move(obj));
}

void arcade::CentipedeGame::updateLazer(std::array<int, 2> pos, std::array<int, 3> RGB)
{
    std::unique_ptr<arcade::AObject> obj = std::make_unique<arcade::AObject>();
    obj->setPos(pos);
    obj->setSize(OBJECT_SIZE);
    obj->setRGB(RGB);
    obj->setAscii('|');
    obj->setAsset("Assets/centipede/lazer.png");
    obj->setType(arcade::Type::Graphic);
    if (_it > 1)
        _map.objects.erase(_map.objects.begin() + 1);
    _map.objects.insert(_map.objects.begin() + 1, std::move(obj));
}
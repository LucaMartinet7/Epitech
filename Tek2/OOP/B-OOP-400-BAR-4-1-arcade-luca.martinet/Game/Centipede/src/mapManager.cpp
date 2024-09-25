/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** mapUtils
*/

#include "CentipedeGame.hpp"
#include "AObject.hpp"
#include <fstream>
#include <iostream>
#include <random>

void arcade::CentipedeGame::createMap(void)
{
    std::ifstream file("Assets/centipede/map.txt");
    std::string str;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    _map.objects.clear();

    if (file.is_open()) {
        int y = 0;
        while (getline(file, str)) {
            for (std::string::size_type x = 0; x < str.size(); ++x) {
                std::unique_ptr<arcade::AObject> obj = std::make_unique<arcade::AObject>();
                obj->setPos({static_cast<int>(x), y});
                obj->setSize(OBJECT_SIZE);
                if (str[x] == '#' || (str[x] == ' ' && dis(gen) <= 2)) {
                    obj->setRGB(WALL_COLOR);
                    obj->setAscii('5');
                    obj->setAsset("Assets/centipede/5.png");
                    obj->setType(arcade::Type::Graphic);
                } else if (str[x] == ' ')
                    continue;
                _map.objects.push_back(std::move(obj));
            }
            ++y;
        }
        _map.size = std::make_pair(str.size(), y);
    }
}

arcade::data_t const &arcade::CentipedeGame::getMap(void) const
{
    return _map;
}


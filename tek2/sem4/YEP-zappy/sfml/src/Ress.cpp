/*
** EPITECH PROJECT, 2024
** B-YEP-400-BAR-4-1-zappy-noe.kurata [WSL: Ubuntu]
** File description:
** Ress
*/

#include "Ress.hpp"

void Ress::initializeRess(std::string name) {
    _name = name;
    if (name == "linemate") {
        _density += 0.3;
        _texture.loadFromFile("assets/linemate.png");
        _sprite.setTexture(_texture);
    } else if (name == "deraumere") {
        _density += 0.15;
        _texture.loadFromFile("assets/deraumere.png");
        _sprite.setTexture(_texture);
    } else if (name == "sibur") {
        _density += 0.1;
        _texture.loadFromFile("assets/sibur.png");
        _sprite.setTexture(_texture);
    } else if (name == "mendiane") {
        _density += 0.1;
        _texture.loadFromFile("assets/mendiane.png");
        _sprite.setTexture(_texture);
    } else if (name == "phiras") {
        _density += 0.08;
        _texture.loadFromFile("assets/phiras.png");
        _sprite.setTexture(_texture);
    } else if (name == "thystame") {
        _density += 0.05;
        _texture.loadFromFile("assets/thystame.png");
        _sprite.setTexture(_texture);
    } else if (name == "food") {
        _density += 0.5;
        _texture.loadFromFile("assets/food.png");
        _sprite.setTexture(_texture);
    }
}

bool Ress::layEgg()
{
    return _density >= 1 ? true : false;
}

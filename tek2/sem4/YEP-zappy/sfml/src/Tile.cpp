/*
** EPITECH PROJECT, 2024
** B-YEP-400-BAR-4-1-zappy-noe.kurata [WSL: Ubuntu]
** File description:
** Tile
*/

#include "Tile.hpp"
#include "Client.hpp"
#include <iostream>

const std::vector<std::vector<Tile>>& Client::getMap() const
{
    return map;
}

Tile::Tile() : isVoid(false), players(0), evolution(-1)
{
    _tile.setSize(sf::Vector2f(100, 100));
    _tile.setFillColor(_color);
    _tile.setOutlineThickness(1);
    _tile.setOutlineColor(_borderColor);
}

Tile::~Tile() {}

void Tile::setPosition(const sf::Vector2f &position)
{
    _tile.setPosition(position);
}

void Tile::print() const
{
    if (isVoid) {
        std::cout << "V";
    } else {
        if (players > 0) {
            std::cout << "P" << players;
        }
        if (evolution >= 0) {
            std::cout << "E" << evolution;
        }
        for (const auto& gem : gems) {
            std::cout << gem.first << gem.second;
        }
    }
}

/*
** EPITECH PROJECT, 2024
** B-YEP-400-BAR-4-1-zappy-noe.kurata
** File description:
** Map
*/

#ifndef TILE_HPP_
#define TILE_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <map>
#include <vector>
#include "Ress.hpp"
#include "Player.hpp"

class Tile {
public:
    Tile();
    ~Tile();
    void setPosition(const sf::Vector2f& position);
    void print() const;

    bool isVoid;
    int players;
    int evolution;
    std::map<std::string, int> gems;

protected:
    sf::RectangleShape _tile;
    sf::Color _color = sf::Color::Green;
    sf::Color _borderColor = sf::Color::Black;
    std::unordered_map<Ress, size_t> _ressources;
    std::vector<Player> _players;
};

#endif /* !TILE_HPP_ */

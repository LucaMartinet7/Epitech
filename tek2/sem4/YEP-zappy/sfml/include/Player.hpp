/*
** EPITECH PROJECT, 2024
** B-YEP-400-BAR-4-1-zappy-noe.kurata
** File description:
** Players
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <unordered_map>

#include "Ress.hpp"

class Player {
    public:
        Player() = default;
        ~Player() = default;
        void createPlayer(int id) {
            _id = id;
            _texture.loadFromFile("assets/player.png");
            _sprite.setTexture(_texture);
        }
        void setLevel(int level) { _level = level; }
        void setLife(size_t life) { _life = life; }
        void setPosition(sf::Vector2f pos) { _sprite.setPosition(pos); }
        int getId() { return _id; }
        int getLevel() { return _level; }
        size_t getLife() { return _life; }
        void addResource(Ress resource, size_t quantity) { _inventory[resource] += quantity; }
        size_t getResourceQuantity(Ress resource) { return _inventory[resource]; }


    protected:
        int _id;
        int _level = 0;
        size_t _life = 1260;
        sf::Texture _texture;
        sf::Sprite _sprite;
        std::unordered_map<Ress, size_t> _inventory;
    private:
};

#endif /* !PLAYERS_HPP_ */

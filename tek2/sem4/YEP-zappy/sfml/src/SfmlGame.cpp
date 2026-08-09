/*
** EPITECH PROJECT, 2024
** B-YEP-400-BAR-4-1-zappy-noe.kurata [WSL: Ubuntu]
** File description:
** SfmlGame
*/

#include "SfmlGame.hpp"

SfmlGame::SfmlGame()
{
}

SfmlGame::~SfmlGame()
{
}

void SfmlGame::init()
{
    _window.create(sf::VideoMode(1920, 1080), "Zappy");
    _bgColor = sf::Color::Black;
}

void SfmlGame::update()
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed) {
            _window.close();
        }
    }
}

bool SfmlGame::isWindowOpen()
{
    return _window.isOpen();
}

void SfmlGame::createTiles(std::pair<int, int> dimensions)
{
    int width = dimensions.first;
    int height = dimensions.second;
    float tileSize = 100.0f;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            Tile tile;
            sf::Vector2f position(x * tileSize, y * tileSize);
            tile.setPosition(position);
            _map.push_back(tile);
        }
    }
}

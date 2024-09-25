/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** entryPoint
*/

#include <memory>

#include "ArcadeSfml.hpp"
#include "AObject.hpp"
#include "AEvent.hpp"

extern "C" std::unique_ptr<arcade::IDisplayModule> entryPoint()
{
    return std::make_unique<arcade::ArcadeSfml>();
}

arcade::ArcadeSfml::ArcadeSfml()
{
    _window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Arcade");
    _window.setFramerateLimit(60);
    _window.setActive(true);
    setTexturesPath("Assets");
    setKeyMap();
}

arcade::ArcadeSfml::~ArcadeSfml()
{
    _window.close();
}

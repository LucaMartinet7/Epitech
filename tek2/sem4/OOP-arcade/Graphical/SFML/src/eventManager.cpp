/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** eventManager
*/

#include <memory>

#include "ArcadeSfml.hpp"
#include "AEvent.hpp"

void arcade::ArcadeSfml::setKeyMap(void)
{
    _keyMap[sf::Keyboard::Up] = "Up";
    _keyMap[sf::Keyboard::Down] = "Down";
    _keyMap[sf::Keyboard::Left] = "Left";
    _keyMap[sf::Keyboard::Right] = "Right";
    _keyMap[sf::Keyboard::Escape] = "Escape";
    _keyMap[sf::Keyboard::Space] = "Space";
    _keyMap[sf::Keyboard::Return] = "Enter";
    _keyMap[sf::Keyboard::L] = "NextL";
    _keyMap[sf::Keyboard::G] = "NextG";
    _keyMap[sf::Keyboard::R] = "Restart";
    _keyMap[sf::Keyboard::M] = "Menu";
    _keyMap[sf::Keyboard::Q] = "Exit";
}

std::vector<std::unique_ptr<arcade::IEvent>> const &arcade::ArcadeSfml::getEvent(void)
{
    _events.clear();

    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Resized) {
            _window.setView(sf::View(sf::FloatRect(0, 0, _event.size.width, _event.size.height)));
        }
        if (_event.type == sf::Event::Closed) {
            _events.push_back(std::make_unique<AEvent>("Exit"));
        }
        if (_event.type == sf::Event::KeyPressed) {
            auto it = _keyMap.find(_event.key.code);
            if (it != _keyMap.end()) {
                _events.push_back(std::make_unique<AEvent>(it->second));
            }
        }
    }
    return _events;
}

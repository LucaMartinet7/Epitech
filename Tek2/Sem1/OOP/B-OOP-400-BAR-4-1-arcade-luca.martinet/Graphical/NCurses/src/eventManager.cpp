/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** eventManager
*/

#include <memory>

#include "ArcadeNCurses.hpp"
#include "AEvent.hpp"

void arcade::ArcadeNCurses::setKeyMap(void)
{
    _keyMap[259] = "Up";
    _keyMap[258] = "Down";
    _keyMap[260] = "Left";
    _keyMap[261] = "Right";
    _keyMap[27] = "Escape";
    _keyMap[32] = "Space";
    _keyMap[10] = "Enter";
    _keyMap['l'] = "NextL";
    _keyMap['g'] = "NextG";
    _keyMap['r'] = "Restart";
    _keyMap['m'] = "Menu";
    _keyMap['q'] = "Exit";
}

std::vector<std::unique_ptr<arcade::IEvent>> const &arcade::ArcadeNCurses::getEvent(void)
{
    _events.clear();

    int ch = getch();
    if (ch == ERR)
        return _events;
    auto it = _keyMap.find(ch);
    if (it != _keyMap.end()) {
        _events.push_back(std::make_unique<AEvent>(it->second));
    }
    return _events;
}

/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** AEvent
*/

#include "AEvent.hpp"

arcade::AEvent::AEvent(std::string type)
{
    _type = type;
}

const std::string &arcade::AEvent::type() const
{
    return _type;
}

arcade::AEvent::~AEvent()
{
    return;
}

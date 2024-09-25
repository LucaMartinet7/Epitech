/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** AObject
*/

#include "AObject.hpp"

arcade::AObject::AObject()
{
    _rgb = {0, 0, 0};
    _pos = {0, 0};
    _size = {0, 0};
    _asset = "";
    _ascii = 0;
    _type = arcade::Type::Graphic;
}

std::array<int, 3> const &arcade::AObject::getRGB(void) const
{
    return _rgb;
}

std::array<int, 2> const &arcade::AObject::getPos(void) const
{
    return _pos;
}

std::array<int, 2> const &arcade::AObject::getSize(void) const
{
    return _size;
}

std::string const &arcade::AObject::getAsset(void) const
{
    return _asset;
}

char arcade::AObject::getAscii(void) const
{
    return _ascii;
}

arcade::Type arcade::AObject::getType(void) const
{
    return _type;
}

void arcade::AObject::setRGB(std::array<int, 3> rgb)
{
    _rgb = rgb;
}

void arcade::AObject::setPos(std::array<int, 2> pos)
{
    _pos = pos;
}

void arcade::AObject::setSize(std::array<int, 2> size)
{
    _size = size;
}

void arcade::AObject::setAsset(std::string asset)
{
    _asset = asset;
}

void arcade::AObject::setAscii(char ascii)
{
    _ascii = ascii;
}

void arcade::AObject::setType(arcade::Type type)
{
    _type = type;
}

arcade::AObject::~AObject()
{
    return;
}

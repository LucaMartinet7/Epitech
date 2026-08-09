/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD12-luca.martinet
** File description:
** Toy
*/

#include "Toy.hpp"
#include <utility>

Toy::Toy() : type(BASIC_TOY), name("toy"), picture(Picture()) {}

Toy::Toy(ToyType type, const std::string &name, const std::string &file) : type(type), name(name), picture(Picture(file)) {}

Toy::~Toy() {}

Toy::Toy(const Toy &other) : type(other.type), name(other.name), picture(other.picture) {}

Toy::ToyType Toy::getType() const
{
    return type;
}

std::string Toy::getName() const
{
    return name;
}

void Toy::setName(const std::string &name)
{
    this->name = name;
}

bool Toy::setAscii(const std::string &file)
{
    return picture.getPictureFromFile(file);
}

std::string Toy::getAscii() const
{
    return picture.data;
}

Toy &Toy::operator=(const Toy &other)
{
    this->name = other.name;
    this->type = other.type;
    this->picture = Picture(other.picture);
    return *this;
}

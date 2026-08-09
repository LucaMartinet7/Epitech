/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD12-luca.martinet
** File description:
** Toy
*/

#include "Toy.hpp"
#include <utility>
#include <iostream>

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
    if (picture.getPictureFromFile(file) == false) {
        this->error = Toy::Error(Error::PICTURE, "bad new illustration", "setAscii");
        return false;
    }
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

bool Toy::speak(const std::string &statement)
{
    std::cout << name << " \"" << statement << "\"" << std::endl;
    return true;
}

bool Toy::speak_es(const std::string &)
{
    this->error = Toy::Error(Error::SPEAK, "wrong mode", "speak_es");
    return false;
}

std::ostream &operator<<(std::ostream &os, const Toy &toy)
{
    os << toy.getName() << std::endl << toy.getAscii() << std::endl;
    return os;
}

Toy &Toy::operator<<(const std::string &str)
{
    this->picture.data = str;
    return *this;
}

Toy::Error::Error(Toy::Error::ErrorType type, std::string what, std::string where) : type(type), _what(std::move(what)), _where(std::move(where)) {}

std::string Toy::Error::what() const noexcept
{
    return this->_what;
}

std::string Toy::Error::where() const noexcept
{
    return this->_where;
}

const Toy::Error &Toy::getLastError() const noexcept
{
    return this->error;
}
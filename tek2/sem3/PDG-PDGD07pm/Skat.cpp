/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD07pm-luca.martinet
** File description:
** Skat
*/

#include "Skat.hpp"
#include <iostream>

Skat::Skat(const std::string &name, int stimPaks) : _name(name), _stock(stimPaks)
{
}

Skat::~Skat()
{
}

int &Skat::stimPaks()
{
    return _stock;
}

const std::string &Skat::name()
{
    return _name;
}

void Skat::shareStimPaks(int number, int &stock)
{
    if (number > this->_stock) {
        std::cout << "Don't be greedy" << std::endl;
        return;
    }
    std::cout << "Keep the change." << std::endl;
    stock += number;
    this->_stock -= number;
}

void Skat::addStimPaks(unsigned int number)
{
    if (number == 0)
        std::cout << "Hey boya, did you forget something?" << std::endl;
    _stock += number;
}

void Skat::useStimPaks()
{
    if (_stock == 0) {
        std::cout << "Mediiiiiic" << std::endl;
    } else {
        _stock -= 1;
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
    }
}

void Skat::status() const
{
    std::cout << "Soldier " << _name
              << " reporting " << _stock << " stimpaks remaining sir!"
              << std::endl;
}

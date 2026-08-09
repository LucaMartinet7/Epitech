/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD09-luca.martinet
** File description:
** Knight
*/

#include "Knight.hpp"
#include <iostream>

Knight::Knight(const std::string& name, int power) : Peasant(name, power)
{
    std::cout << this->name << " vows to protect the kingdom." << std::endl;
}

Knight::~Knight()
{
    std::cout << this->name << " takes off his armor." << std::endl;
}

int Knight::attack()
{
    if (this->hp == 0) {
        std::cout << this->name << " is out of combat." << std::endl;
        return 0;
    } else if (this->power < 10) {
        std::cout << this->name << " is out of power." << std::endl;
        return 0;
    } else {
        this->power -= 10;
        std::cout << this->name << " strikes with his sword." << std::endl;
        return 20;
    }
}

int Knight::special()
{
    if (this->hp == 0) {
        std::cout << this->name << " is out of combat." << std::endl;
        return 0;
    } else if (this->power < 30) {
        std::cout << this->name << " is out of power." << std::endl;
        return 0;
    } else {
        std::cout << this->name << " impales his enemy." << std::endl;
        this->power -= 30;
        return 50;
    }
}

void Knight::rest()
{
    if (this->hp == 0) {
        std::cout << this->name << " is out of combat." << std::endl;
        return;
    }
    else if (this->power >= 50) {
        this->power = 100;
        std::cout << this->name << " eats." << std::endl;
    } else {
        std::cout << this->name << " eats." << std::endl;
        this->power += 50;
    }
}

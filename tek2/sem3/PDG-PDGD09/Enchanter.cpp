/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD09-luca.martinet
** File description:
** Enchanter
*/

#include "Enchanter.hpp"
#include <iostream>

Enchanter::Enchanter(const std::string &name, int power) : Peasant(name, power)
{
    std::cout << this->name << " learns magic from his spellbook." << std::endl;
}

Enchanter::~Enchanter()
{
    std::cout << this->name << " closes his spellbook." << std::endl;
}

int Enchanter::attack()
{
    if (this->hp == 0) {
        std::cout << this->name << " is out of combat." << std::endl;
        return 0;
    } else if (this->power < 10) {
        std::cout << this->name << " is out of power." << std::endl;
        return 0;
    } else {
        this->power -= 0;
        std::cout << this->name << " doesn't know how to fight." << std::endl;
        return 0;
    }
}

int Enchanter::special()
{
    if (this->hp == 0) {
        std::cout << this->name << " is out of combat." << std::endl;
        return 0;
    } else if (this->power < 50) {
        std::cout << this->name << " is out of power." << std::endl;
        return 0;
    } else {
        this->power -= 50;
        std::cout << this->name << " casts a fireball." << std::endl;
        return 99;
    }
}

void Enchanter::rest()
{
    if (this->hp == 0) {
        std::cout << this->name << " is out of combat." << std::endl;
        return;
    } else {
        std::cout << this->name << " meditates." << std::endl;
        this->power = 100;
    }
}

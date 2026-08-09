/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD09-luca.martinet
** File description:
** Priest
*/

#include "Priest.hpp"
#include <iostream>

Priest::Priest(const std::string &name, int power) : Peasant(name, power), Enchanter(name, power)
{
    std::cout << this->name << " enters in the order." << std::endl;
}

Priest::~Priest()
{
    std::cout << this->name << " finds peace." << std::endl;
}

void Priest::rest()
{
    if (this->hp == 0) {
        std::cout << this->name << " is out of combat." << std::endl;
        return;
    } else if (this->power < 0) {
        std::cout << this->name << " is out of power." << std::endl;
        return;
    }
    else {
        std::cout << this->name << " prays." << std::endl;
        this->power = 100;
        this->hp = 100;
    }
}

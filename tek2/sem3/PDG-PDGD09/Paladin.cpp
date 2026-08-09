/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD09-luca.martinet
** File description:
** Paladin
*/

#include "Paladin.hpp"
#include <iostream>

Paladin::Paladin(const std::string &name, int power) : Peasant(name, power), Knight(name, power), Priest(name, power)
{
    std::cout << this->name << " fights for the light." << std::endl;
}

Paladin::~Paladin()
{
    std::cout << this->name << " is blessed." << std::endl;
}

int Paladin::attack()
{
    return this->Knight::attack();
}

int Paladin::special()
{
    return this->Enchanter::special();
}

void Paladin::rest()
{
    this->Priest::rest();
}

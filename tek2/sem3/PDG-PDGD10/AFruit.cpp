/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD10-luca.martinet
** File description:
** AFruit
*/

#include "AFruit.hpp"

AFruit::AFruit(std::string name, unsigned int vitamins, bool peeled) : peeled(peeled), vitamins(vitamins), name(name) {}

std::string AFruit::getName() const
{
    return this->name;
}

bool AFruit::isPeeled() const
{
    return this->peeled;
}

void AFruit::peel()
{
    this->peeled = true;
}

unsigned int AFruit::getVitamins() const
{
    if (this->peeled) {
        return this->vitamins;
    } else {
        return 0;
    }
}

/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD10-luca.martinet
** File description:
** IFruit
*/

#include "IFruit.hpp"
#include <iostream>

std::ostream &operator<<(std::ostream &os, const IFruit &fruit)
{
    std::string peeled;
    if (fruit.isPeeled()) {
        peeled = "true";
    } else {
        peeled = "false";
    }
    os << "[name: \"" << fruit.getName() << "\", vitamins: " << fruit.getVitamins() << ", peeled: " << peeled << "]";
    return os;
}

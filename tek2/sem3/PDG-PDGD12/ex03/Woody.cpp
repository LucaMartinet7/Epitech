/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD12-luca.martinet
** File description:
** Woody
*/

#include "Woody.hpp"
#include <iostream>

Woody::Woody(const std::string &name, const std::string &ascii) : Toy(WOODY, name, ascii) {}

Woody::~Woody() {}

void Woody::speak(const std::string &statement)
{
    std::cout << "WOODY: " << this->getName() << " \"" << statement << "\"" << std::endl;
}

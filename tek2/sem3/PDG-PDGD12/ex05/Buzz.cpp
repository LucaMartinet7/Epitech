/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD12-luca.martinet
** File description:
** Buzz
*/

#include "Buzz.hpp"
#include <iostream>

Buzz::Buzz(const std::string &name, const std::string &ascii) : Toy(BUZZ, name, ascii) {}

bool Buzz::speak(const std::string &statement)
{
    std::cout << "BUZZ: " << this->getName() << " \"" << statement << "\"" << std::endl;
    return true;
}

bool Buzz::speak_es(const std::string &statement)
{
    std::cout << "BUZZ: " << this->getName() << " senorita \"" << statement << "\" senorita" << std::endl;
    return true;
}

Buzz::~Buzz() {}
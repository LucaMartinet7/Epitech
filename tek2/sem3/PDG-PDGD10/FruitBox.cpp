/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD10-luca.martinet
** File description:
** FruitBox
*/

#include "FruitBox.hpp"
#include <iostream>
#include <algorithm>

FruitBox::FruitBox(unsigned int size) : size(size) {}

FruitBox::~FruitBox()
{
    for (IFruit* fruit : fruits) {
        delete fruit;
    }
}

unsigned int FruitBox::getSize() const
{
    return size;
}

unsigned int FruitBox::nbFruits() const
{
    return fruits.size();
}

const IFruit* FruitBox::getFruits(unsigned int i) const
{
    return fruits.at(i);
}

bool FruitBox::pushFruit(IFruit* fruit)
{
    if (fruits.size() >= size || std::find(fruits.begin(), fruits.end(), fruit) != fruits.end()) {
        return false;
    }
    fruits.push_back(fruit);
    return true;
}

IFruit* FruitBox::popFruit()
{
    if (fruits.empty()) {
        return nullptr;
    }

    IFruit* frontFruit = fruits.front();
    fruits.erase(fruits.begin());
    return frontFruit;
}

std::ostream& operator<<(std::ostream& os, const FruitBox& box)
{
    os << std::string("[");
    for (unsigned int i = 0; i < box.nbFruits(); ++i) {
        os << *box.getFruits(i);
        if (i != box.nbFruits() - 1) {
            os << std::string(", ");
        }
    }
    os << std::string("]");
    return os;
}

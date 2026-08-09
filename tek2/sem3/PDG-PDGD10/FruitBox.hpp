/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD10-luca.martinet
** File description:
** FruitBox
*/

#ifndef FRUITBOX_HPP_
    #define FRUITBOX_HPP_

#include <iostream>
#include <string>
#include <vector>
#include "IFruit.hpp"

class FruitBox {
public:
    FruitBox(unsigned int size);
    ~FruitBox();

    unsigned int getSize() const;
    unsigned int nbFruits() const;
    bool pushFruit(IFruit* fruit);
    IFruit* popFruit();
    const IFruit* getFruits(unsigned int) const;

private:
    unsigned int size;
    std::vector<IFruit*> fruits;
};

std::ostream& operator<<(std::ostream& os, const FruitBox& box);

#endif /* !FRUITBOX_HPP_ */

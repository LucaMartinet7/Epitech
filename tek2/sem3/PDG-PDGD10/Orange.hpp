/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD10-luca.martinet
** File description:
** Orange
*/

#ifndef ORANGE_HPP_
#define ORANGE_HPP_

#include "ACitrus.hpp"

class Orange : public ACitrus {
    public:
        Orange();
        Orange(std::string name, unsigned int vitamins);
};

#endif /* !ORANGE_HPP_ */

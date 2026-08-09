/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD10-luca.martinet
** File description:
** ANut
*/

#ifndef ANUT_HPP_
    #define ANUT_HPP_
#include "AFruit.hpp"

class ANut : public AFruit {
    protected:
        ANut(const std::string &name, unsigned int vitamins);
};

#endif /* !ANUT_HPP_ */

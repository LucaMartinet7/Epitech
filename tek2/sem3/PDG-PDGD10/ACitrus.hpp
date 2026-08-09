/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD10-luca.martinet
** File description:
** ACitrus
*/

#ifndef ACITRUS_HPP_
    #define ACITRUS_HPP_

#include "AFruit.hpp"


class ACitrus : public AFruit {
protected:
    ACitrus(const std::string& name, unsigned vitamins);
};

#endif /* !ACITRUS_HPP_ */

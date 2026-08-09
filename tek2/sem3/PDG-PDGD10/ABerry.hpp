/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD10-luca.martinet
** File description:
** ABerry
*/

#ifndef ABERRY_HPP_
    #define ABERRY_HPP_

#include "AFruit.hpp"

class ABerry : public AFruit {
    protected:
        ABerry(const std::string& name, unsigned vitamins);
};



#endif /* !ABERRY_HPP_ */

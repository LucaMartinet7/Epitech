/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD09-luca.martinet
** File description:
** Paladin
*/

#ifndef PALADIN_HPP_
    #define PALADIN_HPP_

#include "Knight.hpp"
#include "Priest.hpp"
#include <string>

class Paladin : public Knight, public Priest {
    public:
        Paladin(const std::string& name, int power);
        ~Paladin();

        int attack();
        int special();
        void rest();

    protected:
};

#endif /* !PALADIN_HPP_ */

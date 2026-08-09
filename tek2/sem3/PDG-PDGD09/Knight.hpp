/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD09-luca.martinet
** File description:
** Knight
*/

#ifndef KNIGHT_HPP_
    #define KNIGHT_HPP_

#include "Peasant.hpp"
#include <string>

class Knight : virtual public Peasant {
    public:
        Knight(const std::string& name, int power);
        ~Knight();

        int attack();
        int special();
        void rest();
};

#endif /* !KNIGHT_HPP_ */

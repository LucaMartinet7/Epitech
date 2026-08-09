/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD09-luca.martinet
** File description:
** Enchanter
*/

#ifndef ENCHANTER_HPP_
    #define ENCHANTER_HPP_

#include "Peasant.hpp"
#include <string>

class Enchanter : virtual public Peasant {
    public:
        Enchanter(const std::string& name, int power);
        ~Enchanter();

        int attack();
        int special();
        void rest();
    protected:
};

#endif /* !ENCHANTER_HPP_ */

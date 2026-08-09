/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD09-luca.martinet
** File description:
** PoisonPotion
*/

#ifndef POISONPOTION_HPP_
    #define POISONPOTION_HPP_

#include "IPotion.hpp"

class PoisonPotion : virtual public IPotion {
    public:
        int getHp() const;
        int getPower() const;
};

#endif /* !POISONPOTION_HPP_ */

/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD09-luca.martinet
** File description:
** HealthPotion
*/

#ifndef HEALTHPOTION_HPP_
    #define HEALTHPOTION_HPP_

#include "IPotion.hpp"

class HealthPotion : virtual public IPotion {
    public:
        int getHp() const;
        int getPower() const;
};

#endif /* !HEALTHPOTION_HPP_ */

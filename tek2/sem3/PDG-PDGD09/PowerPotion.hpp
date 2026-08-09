/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD09-luca.martinet
** File description:
** PowerPotion
*/

#ifndef POWERPOTION_HPP_
    #define POWERPOTION_HPP_

#include "IPotion.hpp"

class PowerPotion : virtual public IPotion {
    public:
        int getHp() const ;
        int getPower() const;
};

#endif /* !POWERPOTION_HPP_ */

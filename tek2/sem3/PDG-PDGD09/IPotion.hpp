/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD09-luca.martinet
** File description:
** IPotion
*/

#ifndef IPOTION_HPP_
#define IPOTION_HPP_

#include <iostream>

class IPotion {
    public:
        virtual int getHp() const = 0;
        virtual int getPower() const = 0;
};

#endif /* !IPOTION_HPP_ */

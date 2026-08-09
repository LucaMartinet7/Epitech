/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD09-luca.martinet
** File description:
** ICharacter
*/

#ifndef ICHARACTER_HPP_
    #define ICHARACTER_HPP_

#include "HealthPotion.hpp"
#include "PowerPotion.hpp"
#include "PoisonPotion.hpp"
#include <string>


class ICharacter {
    public:
        ICharacter() {};
        virtual ~ICharacter() {};

        virtual const std::string& getName() const = 0;
        virtual int getPower() const = 0;
        virtual int getHp() const = 0;
        virtual int attack() = 0;
        virtual int special() = 0;
        virtual void rest() = 0;
        virtual void damage(int damage) = 0;

        virtual void drink(const HealthPotion &potion) = 0;
        virtual void drink(const PowerPotion &potion) = 0;
        virtual void drink(const PoisonPotion &potion) = 0;
        virtual void drink(const IPotion &potion) = 0;

    protected:
};

#endif /* !ICHARACTER_HPP_ */

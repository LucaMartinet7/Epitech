/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD09-luca.martinet
** File description:
** Peasant
*/

#include "Peasant.hpp"
#include <iostream>

Peasant::Peasant(const std::string &name, int power) : name(name) , power(std::min(std::max(power, 0), 100))
{
    std::cout << this->name << " goes for an adventure." << std::endl;
}

Peasant::~Peasant()
{
    std::cout << this->name << " is back to his crops." << std::endl;
}

const std::string &Peasant::getName() const
{
    return this->name;
}

int Peasant::getPower() const
{
    return this->power;
}

int Peasant::getHp() const
{
    return this->hp;
}

int Peasant::attack()
{
    if (this->hp == 0) {
        std::cout << this->name << " is out of combat." << std::endl;
        return 0;
    } else if (this->power < 10) {
        std::cout << this->name << " is out of power." << std::endl;
        return 0;
    } else {
        this->power -= 10;
        std::cout << this->name << " tosses a stone." << std::endl;
        return 5;
    }
}

int Peasant::special()
{
    if (this->hp == 0) {
        std::cout << this->name << " is out of combat." << std::endl;
        return 0;
    } else {
        std::cout << this->name << " doesn't know any special move." << std::endl;
        return 0;
    }
}

void Peasant::rest()
{
    if (this->hp == 0) {
        std::cout << this->name << " is out of combat." << std::endl;
        return;
    } else if (this->power >= 70) {
        this->power = 100;
        std::cout << this->name << " takes a nap." << std::endl;
    } else {
        this->power += 30;
        std::cout << this->name << " takes a nap." << std::endl;
    }
}


void Peasant::damage(int damage)
{
    int newHp = std::min(std::max(this->hp - damage, 0), 100);

    if (newHp == 0) {
        std::cout << this->name << " is out of combat." << std::endl;
    } else {
        std::cout << this->name << " takes " << damage << " damage." << std::endl;
    }
    this->hp = newHp;
}

void Peasant::drink(const HealthPotion &potion)
{
    if (potion.getHp() > 0) {
        this->hp = (this->hp + potion.getHp() <= 100) ? this->hp + potion.getHp() : 100;
    } else {
        this->hp = (this->hp + potion.getHp() >= 0) ? this->hp + potion.getHp() : 0;
    }

    if (potion.getPower() > 0) {
        this->power = (this->power + potion.getPower() <= 100) ? this->power + potion.getPower() : 100;
    } else {
        this->power = (this->power + potion.getPower() >= 0) ? this->power + potion.getPower() : 0;
    }
    std::cout << this->name << " feels rejuvenated." << std::endl;
}

void Peasant::drink(const PowerPotion &potion)
{
    if (potion.getHp() > 0) {
        this->hp = (this->hp + potion.getHp() <= 100) ? this->hp + potion.getHp() : 100;
    } else {
        this->hp = (this->hp + potion.getHp() >= 0) ? this->hp + potion.getHp() : 0;
    }

    if (potion.getPower() > 0) {
        this->power = (this->power + potion.getPower() <= 100) ? this->power + potion.getPower() : 100;
    } else {
        this->power = (this->power + potion.getPower() >= 0) ? this->power + potion.getPower() : 0;
    }
    std::cout << this->name << "'s power is restored." << std::endl;
}

void Peasant::drink(const PoisonPotion &potion)
{
    if (potion.getHp() > 0) {
        this->hp = (this->hp + potion.getHp() <= 100) ? this->hp + potion.getHp() : 100;
    } else {
        this->hp = (this->hp + potion.getHp() >= 0) ? this->hp + potion.getHp() : 0;
    }

    if (potion.getPower() > 0) {
        this->power = (this->power + potion.getPower() <= 100) ? this->power + potion.getPower() : 100;
    } else {
        this->power = (this->power + potion.getPower() >= 0) ? this->power + potion.getPower() : 0;
    }
    std::cout << this->name << " has been poisoned." << std::endl;
}

void Peasant::drink(const IPotion &potion)
{
    if (potion.getHp() > 0) {
        this->hp = (this->hp + potion.getHp() <= 100) ? this->hp + potion.getHp() : 100;
    } else {
        this->hp = (this->hp + potion.getHp() >= 0) ? this->hp + potion.getHp() : 0;
    }

    if (potion.getPower() > 0) {
        this->power = (this->power + potion.getPower() <= 100) ? this->power + potion.getPower() : 100;
    } else {
        this->power = (this->power + potion.getPower() >= 0) ? this->power + potion.getPower() : 0;
    }
    std::cout << this->name << " drinks a mysterious potion." << std::endl;
}

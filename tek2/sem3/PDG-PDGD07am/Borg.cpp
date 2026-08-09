/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD07am-luca.martinet
** File description:
** Borg
*/

#include <iostream>
#include "Borg.hpp"
#include "Federation.hpp"

Borg::Ship::Ship(int frequency, short repair)
{
    this->_length = 300;
    this->_maxWarp = 9;
    this->_home = UNICOMPLEX;
    this->_location = this->_home;
    this->_shield = 100;
    this->_weaponFrequency = frequency;
    this->_repair = repair;
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl << "Your biological characteristics and technologies will be assimilated." << std::endl << "Resistance is futile." <<std::endl;
}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
    this->_Core = core;
}

void Borg::Ship::checkCore()
{
    if (this->_Core->checkReactor()->isStable() == true)
        std::cout << "Everything is in order." << std::endl;
    else
        std::cout << "Critical failure imminent" << std::endl;
}

bool Borg::Ship::move(int wrap, Destination d)
{
    if (wrap > this->_maxWarp || d == this->_location || this->_Core->checkReactor()->isStable() == false)
        return false;
    this->_location = d;
    return true;
}

bool Borg::Ship::move(int wrap)
{
    if (wrap > this->_maxWarp || this->_Core->checkReactor()->isStable() == false)
        return false;
    this->_location = this->_home;
    return true;
}

bool Borg::Ship::move(Destination d)
{
    if (d == this->_location || this->_Core->checkReactor()->isStable() == false)
        return false;
    this->_location = d;
    return true;
}

bool Borg::Ship::move()
{
    if (this->_Core->checkReactor()->isStable() == false)
        return false;
    this->_location = this->_home;
    return true;
}

int Borg::Ship::getShield()
{
    return this->_shield;
}

void Borg::Ship::setShield(int nb)
{
    this->_shield = nb;
}

int Borg::Ship::getWeaponFrequency()
{
    return this->_weaponFrequency;
}

void Borg::Ship::setWeaponFrequency(int nb)
{
    this->_weaponFrequency = nb;
}

short Borg::Ship::getRepair()
{
    return this->_repair;
}

void Borg::Ship::setRepair(short nb)
{
    this->_repair = nb;
}

void Borg::Ship::repair()
{
    if (this->_repair == 0)
        std::cout << "Energy cells depleted, shield weakening." << std::endl;
    else
    {
        this->_shield = 100;
        this->_repair -= 1;
        std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions." << std::endl;
    }
}

void Borg::Ship::fire(Federation::Starfleet::Ship *ship)
{
    ship->setShield(ship->getShield() - this->_weaponFrequency);
    std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
}

void Borg::Ship::fire(Federation::Ship *ship)
{
    ship->setShield(ship->getShield() - this->_weaponFrequency);
    std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
}

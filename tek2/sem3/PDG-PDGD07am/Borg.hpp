/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD07am-luca.martinet
** File description:
** Borg
*/

#ifndef BORG_HPP_
    #define BORG_HPP_

#include <string>
#include "Destination.hpp"
#include "WarpSystem.hpp"
#include "Federation.hpp"

namespace Federation
{
    namespace Starfleet
    {
        class Ship;
    }
    class Ship;
}

namespace Borg
{
    class Ship
    {
    public:
        Ship(int frequency = 20, short repair = 3);
        void setupCore(WarpSystem::Core *core);
        void checkCore();
        bool move(int wrap, Destination d);
        bool move(int wrap);
        bool move(Destination d);
        bool move();
        int getShield();
        void setShield(int shield);
        int getWeaponFrequency();
        void setWeaponFrequency(int frequency);
        short getRepair();
        void setRepair(short repair);
        void fire(Federation::Starfleet::Ship *target);
        void fire(Federation::Ship *target);
        void repair();
    private:
        int _length;
        int _width;
        std::string _name;
        short _maxWarp;
        WarpSystem::Core *_Core;
        Destination _location;
        Destination _home;
        int _weaponFrequency;
        int _shield;
        short _repair;
    };
}

#endif /* !BORG_HPP_ */

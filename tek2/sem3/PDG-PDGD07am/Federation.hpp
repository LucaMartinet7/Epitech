/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD07am-luca.martinet
** File description:
** Federation
*/

#ifndef FEDERATION_HPP_
    #define FEDERATION_HPP_

#include <string>
#include "WarpSystem.hpp"
#include "Destination.hpp"
#include "Borg.hpp"

namespace Borg
{
  class Ship;
}

namespace Federation
{
    namespace Starfleet
    {
        class Captain
        {
        public:
            Captain(std::string _name);
            void setAge(int age);
            int	getAge();
            std::string	getName();
        private:
            std::string	_name;
            int	_age;
        };

        class	Ensign
        {
        public:
            Ensign(std::string _name);
        private:
            std::string	_name;
        };

        class Ship
        {
        public:
            Ship(int length, int width, std::string name, short maxWarp, int torpedo = 0);
            Ship();
            void setupCore(WarpSystem::Core *core);
            void checkCore();
            void promote(Federation::Starfleet::Captain *cap);
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
            int getShield();
            void setShield(int shield);
            int getTorpedo();
            void setTorpedo(int torpedo);
            void fire(int torpedoes, Borg::Ship *target);
            void fire(Borg::Ship *target);
        private:
            Federation::Starfleet::Captain *_captain;
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core *_Core;
            Destination _location;
            Destination _home;
            int _shield;
            int _photonTorpedo;
        };
    }

    class Ship
    {
    public:
        Ship(int length, int width, std::string name);
        void setupCore(WarpSystem::Core *core);
        void checkCore();
        WarpSystem::Core *getCore();
        bool move(int warp, Destination d);
        bool move(int wrap);
        bool move(Destination d);
        bool move();
        int getShield();
        void setShield(int shield);
    private:
        int _length;
        int _width;
        std::string _name;
        short _maxWarp;
        WarpSystem::Core *_Core;
        Destination _location;
        Destination _home;
        int _shield;
    };
}

#endif /* !FEDERATION_HPP_ */

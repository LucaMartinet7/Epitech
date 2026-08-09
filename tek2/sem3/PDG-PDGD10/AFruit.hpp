/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD10-luca.martinet
** File description:
** AFruit
*/

#ifndef AFRUIT_HPP_
    #define AFRUIT_HPP_

#include "IFruit.hpp"
#include <string>

class AFruit : virtual public IFruit {
    public:
        unsigned int getVitamins() const;
        std::string getName() const;
        bool isPeeled() const;
        void peel();

    protected:
        AFruit(std::string name, unsigned int vitamins, bool peeled = false);

    private:
        bool peeled;
        unsigned int vitamins;
        std::string name;
};

#endif /* !AFRUIT_HPP_ */

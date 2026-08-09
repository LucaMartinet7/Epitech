/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD09-luca.martinet
** File description:
** Priest
*/

#ifndef PRIEST_HPP_
    #define PRIEST_HPP_

#include "Enchanter.hpp"
#include <string>

class Priest : public Enchanter {
    public:
        Priest(const std::string& name, int power);
        ~Priest();

        void rest();

    protected:
};

#endif /* !PRIEST_HPP_ */

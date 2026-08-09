/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD12-luca.martinet
** File description:
** Woody
*/

#ifndef WOODY_HPP_
    #define WOODY_HPP_

#include "Toy.hpp"

class Woody : virtual public Toy {
    public:
        Woody();
        ~Woody();
        explicit Woody(const std::string &name, const std::string &ascii = "woody.txt");

};

#endif /* !WOODY_HPP_ */

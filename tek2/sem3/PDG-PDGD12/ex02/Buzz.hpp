/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD12-luca.martinet
** File description:
** Buzz
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_

#include "Toy.hpp"

class Buzz : virtual public Toy {
    public:
        ~Buzz();
        explicit Buzz(const std::string &name, const std::string &ascii = "buzz.txt");
};

#endif /* !BUZZ_HPP_ */

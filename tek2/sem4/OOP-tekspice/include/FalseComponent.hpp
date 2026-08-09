/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-tekspice-noe.kurata
** File description:
** FalseComponent
*/

#ifndef FALSECOMPONENT_HPP_
#define FALSECOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts {
    class FalseComponent : public AComponent{
        public:
            ~FalseComponent() = default;
            Tristate compute(std::size_t pin);
    };
};

#endif /* !FALSECOMPONENT_HPP_ */

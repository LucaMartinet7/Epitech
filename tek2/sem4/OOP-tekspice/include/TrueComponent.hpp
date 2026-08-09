/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-tekspice-noe.kurata
** File description:
** TrueComponent
*/

#ifndef TRUECOMPONENT_HPP_
#define TRUECOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts {
    class TrueComponent : public AComponent {
        public:
            ~TrueComponent() = default;
            Tristate compute(std::size_t pin);
    };
};

#endif /* !TRUECOMPONENT_HPP_ */

/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-tekspice-noe.kurata
** File description:
** NotComponent
*/

#ifndef NOTCOMPONENT_HPP_
#define NOTCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts {
    class NotComponent : public AComponent {
        public:
            ~NotComponent() = default;
            Tristate compute(std::size_t pin);
    };
};

#endif /* !NOTCOMPONENT_HPP_ */

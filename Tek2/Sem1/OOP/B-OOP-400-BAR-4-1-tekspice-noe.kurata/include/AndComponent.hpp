/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-tekspice-noe.kurata
** File description:
** AndComponent
*/

#ifndef ANDCOMPONENT_HPP_
    #define ANDCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts {
    class AndComponent : public AComponent {
        public:
            ~AndComponent() = default;
            Tristate compute(std::size_t pin);
    };
};
#endif /* !ANDCOMPONENT_HPP_ */

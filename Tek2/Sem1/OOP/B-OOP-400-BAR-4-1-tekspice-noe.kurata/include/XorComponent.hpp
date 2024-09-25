/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-tekspice-noe.kurata
** File description:
** XorComponent
*/

#ifndef XORCOMPONENT_HPP_
    #define XORCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts {
    class XorComponent : public AComponent {
        public:
            ~XorComponent() = default;
            Tristate compute(std::size_t pin);
    };
};

#endif /* !XORCOMPONENT_HPP_ */

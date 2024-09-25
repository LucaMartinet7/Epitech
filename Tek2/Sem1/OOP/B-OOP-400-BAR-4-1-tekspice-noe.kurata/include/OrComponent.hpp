/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-tekspice-noe.kurata
** File description:
** OrComponent
*/

#ifndef ORCOMPONENT_HPP_
    #define ORCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts {
    class OrComponent : public AComponent {
        public:
            ~OrComponent() = default;
            Tristate compute(std::size_t);
    };
};

#endif /* !ORCOMPONENT_HPP_ */

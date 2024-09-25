/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-tekspice-noe.kurata
** File description:
** TrueComponent
*/

#include "TrueComponent.hpp"

namespace nts {
    Tristate TrueComponent::compute(std::size_t pin)
    {
        if (pin == 1)
            return Tristate::True;
        return Tristate::Undefined;
    }
}

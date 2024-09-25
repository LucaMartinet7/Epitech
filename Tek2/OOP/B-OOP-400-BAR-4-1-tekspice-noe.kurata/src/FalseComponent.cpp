/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-tekspice-noe.kurata
** File description:
** FalseComponent
*/

#include "FalseComponent.hpp"

namespace nts {
    Tristate FalseComponent::compute(std::size_t pin)
    {
        if (pin == 1)
            return Tristate::False;
        return Tristate::Undefined;
    }
}

/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-tekspice-noe.kurata
** File description:
** OrComponent
*/

#include "OrComponent.hpp"
#include "Throws.hpp"

namespace nts {

    Tristate OrComponent::compute(std::size_t pin)
    {
        if (pin != 3)
            throw nts::InvalidPinException("Invalid pin for OR component computation");

        auto [comp1, pin1] = getLink(1);
        auto [comp2, pin2] = getLink(2);
        Tristate state1 = comp1->compute(pin1);
        Tristate state2 = comp2->compute(pin2);

        if (state1 != Tristate::Undefined || state2 != Tristate::Undefined) {
            if (state1 == Tristate::True || state2 == Tristate::True) {
                return Tristate::True;
            }
            return Tristate::False;
        }
        return Tristate::Undefined;
    }
}

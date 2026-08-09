/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-tekspice-noe.kurata
** File description:
** NotComponent
*/

#include "NotComponent.hpp"
#include "Throws.hpp"

namespace nts {
    Tristate NotComponent::compute(std::size_t pin) {
        if (pin != 1)
            throw nts::InvalidPinException("Invalid pin for NOT component");

        auto [comp, inpin] = getLink(1);
        Tristate state = comp->compute(inpin);

        if (state != Tristate::Undefined) {
            if (state == Tristate::True)
                return Tristate::False;
            return Tristate::True;
        }
        return Tristate::Undefined;
    }
}

/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-tekspice-noe.kurata
** File description:
** InputComponent
*/

#include "InputComponent.hpp"
#include "Throws.hpp"

namespace nts {

    void InputComponent::simulate(std::size_t)
    {
        _state1 = _state2;
    }

    Tristate InputComponent::compute(std::size_t)
    {
        return _state1;
    }

    void InputComponent::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
    {
        if (pin == 1) {
            _comp = &other;
            _pin = otherPin;
        } else {
            throw nts::InvalidPinException("Invalid pin for input component", "setLink");
        }
}

    void InputComponent::setState(Tristate state)
    {
        _state2 = state;
    }
}

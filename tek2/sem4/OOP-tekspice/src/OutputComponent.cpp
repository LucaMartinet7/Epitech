/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-tekspice-noe.kurata
** File description:
** OutputComponent
*/

#include "OutputComponent.hpp"

namespace nts {

    void OutputComponent::simulate(std::size_t) {}

    Tristate OutputComponent::compute(std::size_t)
    {
        if (_comp)
            return _comp->compute(_pin);
        return Tristate::Undefined;
    }

    void OutputComponent::setLink(std::size_t, IComponent &other, std::size_t otherPin)
    {
        _comp = &other;
        _pin = otherPin;
    }
}

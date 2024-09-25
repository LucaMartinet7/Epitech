/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-tekspice-noe.kurata
** File description:
** AComponent
*/

#include "AComponent.hpp"
#include "Throws.hpp"

namespace nts {

    void AComponent::simulate(std::size_t tick)
    {
        (void)tick;
    }

    void AComponent::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
    {
        if (_links.find(pin) != _links.end())
            throw PinAlreadyLinkedException("pin already linked");
        _links[pin] = std::make_pair(&other, otherPin);
    }

    std::pair<IComponent *, std::size_t> AComponent::getLink(std::size_t pin) const
    {
        auto it = _links.find(pin);
        if (it == _links.end())
            throw std::out_of_range("Pin not connected: " + std::to_string(pin));
        return it->second;
    }
}

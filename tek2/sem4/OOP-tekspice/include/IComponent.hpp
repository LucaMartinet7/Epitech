/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-tekspice-noe.kurata
** File description:
** Icomp
*/

#ifndef IComponent_HPP
#define IComponent_HPP

#include <iostream>

namespace nts {
    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false
    };

    class IComponent {
    public:
        virtual ~IComponent() = default;
        virtual void simulate(std::size_t tick) = 0;
        virtual nts::Tristate compute(std::size_t pin) = 0;
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
    };
}


#endif //IComponent_HPP
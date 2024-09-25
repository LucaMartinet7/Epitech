/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-tekspice-noe.kurata
** File description:
** InputComponent
*/

#ifndef INPUTCOMPONENT_HPP_
#define INPUTCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts {
    class InputComponent : public IComponent{
        public:
            void simulate(std::size_t) override;
            Tristate compute(std::size_t) override;
            void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override;
            void setState(Tristate state);
        protected:
            Tristate _state1 = Tristate::Undefined; //old state
            Tristate _state2 = Tristate::Undefined; //new state
            IComponent *_comp = nullptr;
            std::size_t _pin = 0;

    };
}

#endif /* !INPUTCOMPONENT_HPP_ */

/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-tekspice-noe.kurata
** File description:
** OutputComponent
*/

#ifndef OUTPUTCOMPONENT_HPP_
#define OUTPUTCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts {
    class OutputComponent : public IComponent {
        public:
            void simulate(std::size_t) override;
            Tristate compute(std::size_t) override;
            void setLink(std::size_t, IComponent &other, std::size_t otherPin) override;
        protected:
            IComponent *_comp = nullptr;
            std::size_t _pin = 0;
    };

}

#endif /* !OUTPUTCOMPONENT_HPP_ */

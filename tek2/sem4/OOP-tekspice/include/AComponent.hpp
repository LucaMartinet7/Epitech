/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-tekspice-noe.kurata
** File description:
** AComponent
*/

#ifndef AComponent_HPP
#define AComponent_HPP

#include <unordered_map>

#include "IComponent.hpp"

namespace nts {

    class AComponent : public IComponent {
    public:
        virtual ~AComponent() {};
        virtual Tristate compute(std::size_t pin) override = 0;
        void simulate(std::size_t tick) override;
        void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override;
        std::pair<IComponent *, std::size_t> getLink(std::size_t pin) const;
        Tristate getState(size_t pin);

    protected:
        std::unordered_map<std::size_t, std::pair<IComponent*, std::size_t> > _links;
    };
}

#endif /* !ACOMPONENT_HPP_ */

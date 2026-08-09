/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-tekspice-noe.kurata
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include <unordered_map>
#include <memory>
#include "vector"
#include "AComponent.hpp"

namespace nts {
    class Circuit {
        public:
            Circuit();
            void simulate(std::size_t tick);
            std::size_t getTick() const { return _tick; }
            void createComponent(const std::string &type, const std::string &value);
            void setLink(std::size_t pin, IComponent &other, std::size_t otherPin);
            void setInputValue(const std::string &name, const std::string &value);
            void displayComponents();
        protected:
        std::unordered_map<std::string, std::unique_ptr<IComponent>> _components;
        std::size_t _tick;
    };
}

#endif /* !CIRCUIT_HPP_ */

/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-tekspice-noe.kurata
** File description:
** factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include <memory>
#include <unordered_map>
#include "IComponent.hpp"


namespace nts {
    class Factory {
    public:
        Factory();

        std::unique_ptr<nts::IComponent>
        createComponent(const std::string &type);
    private:
        template<typename T>
        std::unique_ptr<IComponent> registerComponent()
        {
            return std::make_unique<T>();
        }

        std::unordered_map<std::string, std::unique_ptr<IComponent> (Factory::*)()> _constructors;
    };
}

#endif /* !FACTORY_HPP_ */

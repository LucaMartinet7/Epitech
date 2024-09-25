/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-tekspice-noe.kurata
** File description:
** factory
*/

#include <memory>
#include "Factory.hpp"
#include "Throws.hpp"
#include "AndComponent.hpp"
#include "NotComponent.hpp"
#include "InputComponent.hpp"
#include "OutputComponent.hpp"
#include "TrueComponent.hpp"
#include "FalseComponent.hpp"
#include "XorComponent.hpp"
#include "OrComponent.hpp"

namespace nts {
    Factory::Factory()
    {
        _constructors["input"] = &Factory::registerComponent<InputComponent>;
        _constructors["output"] = &Factory::registerComponent<OutputComponent>;
        _constructors["and"] = &Factory::registerComponent<AndComponent>;
        _constructors["not"] = &Factory::registerComponent<NotComponent>;
        _constructors["true"] = &Factory::registerComponent<TrueComponent>;
        _constructors["false"] = &Factory::registerComponent<FalseComponent>;
        _constructors["or"] = &Factory::registerComponent<OrComponent>;
        _constructors["xor"] = &Factory::registerComponent<XorComponent>;
    }

    std::unique_ptr<IComponent> Factory::createComponent(const std::string &type)
    {
        if (_constructors.find(type) == _constructors.end())
            throw InvalidComponentTypeException("Factory: Unknown component type");
        return (this->*_constructors[type])();
    }
}

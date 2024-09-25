/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-tekspice-noe.kurata
** File description:
** Circuit
*/

#include "Factory.hpp"
#include "InputComponent.hpp"
#include "OutputComponent.hpp"
#include "Throws.hpp"
#include "Circuit.hpp"

namespace nts {

    Circuit::Circuit()
    {
        _tick = 0;
    }

    void Circuit::simulate(std::size_t tick)
    {
        if (_tick == tick)
            return;
    }


    void Circuit::createComponent(const std::string &type, const std::string &value)
    {
        Factory factory;

        if (_components.find(value) != _components.end())
            throw InvalidPinException("Circuit: component creation failed: duplicated name");
        _components[value] = std::move(factory.createComponent(type));
    }

    void Circuit::setInputValue(const std::string &name, const std::string &str)
    {
        auto it = _components.find(name);
        if (it == _components.end())
        {
            std::cerr << "Input '" << name << "' not found." << std::endl;
            return;
        }

        auto inputComponent = dynamic_cast<InputComponent *>(it->second.get());
        if (!inputComponent)
        {
            std::cerr << "Component '" << name << "' is not an input." << std::endl;
            return;
        }

        nts::Tristate value = nts::Tristate::Undefined;
        if (str == "1")
        {
            value = nts::Tristate::True;
        }
        else if (str == "0")
        {
            value = nts::Tristate::False;
        }

        inputComponent->setState(value);
    }

    Tristate checkTristate(Tristate state)
    {
        if (state != Tristate::Undefined) {
            if (state == Tristate::True) {
                return Tristate::True;
            } else {
                return Tristate::False;
            }
        }
        return Tristate::Undefined;
    }

    std::string tristateToString(Tristate state) {
        switch (state) {
            case Tristate::True:
                return "1";
            case Tristate::False:
                return "0";
            default:
                return "U";
        }
    }

    void Circuit::displayComponents()
    {
        std::cout << "input(s):" << std::endl;
        for (const auto &component : _components) {
            InputComponent* input = dynamic_cast<InputComponent*>(component.second.get());
            if (input != nullptr) {
                std::cout << component.first << ": " << tristateToString(checkTristate(input->compute(1))) << std::endl;
            }
        }
        std::cout << "output(s):" << std::endl;
        for (const auto &component : _components) {
            OutputComponent* output = dynamic_cast<OutputComponent*>(component.second.get());
            if (output != nullptr) {
                std::cout << component.first << ": " << tristateToString(checkTristate(output->compute(1))) << std::endl;
            }
        }
    }
}
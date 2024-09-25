/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-tekspice-noe.kurata
** File description:
** shell
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <csignal>
#include "Shell.hpp"

namespace nts{
    Shell::Shell()
    {
        this->commands["exit"] = &Shell::exit;
        this->commands["display"] = &Shell::display;
        this->commands["simulate"] = &Shell::simulate;
        // this->commands["loop"] = &Shell::loop;
    }

    void Shell::exit()
    {
        std::cin.setstate(std::ios::eofbit);
    }

    void Shell::display()
    {
        std::cout << "tick: " << this->_tick << std::endl;
        _parsedcircuit->displayComponents();
    }

    void Shell::simulate()
    {
        this->_tick++;
    }

    bool Shell::UserInput()
    {
        if (std::cin.eof())
            return false;
        std::cout << "> ";
        getline(std::cin, this->_input);
        if (std::cin.eof())
            return false;
        return true;
    }

    void Shell::runShell(Circuit *circuit)
    {
        std::string line;
        _parsedcircuit = circuit;

        while (this->UserInput()) {
            if (this->commands.find(this->_input) != this->commands.end()) {
                (this->*commands[this->_input])();
            }
        }
    }
}

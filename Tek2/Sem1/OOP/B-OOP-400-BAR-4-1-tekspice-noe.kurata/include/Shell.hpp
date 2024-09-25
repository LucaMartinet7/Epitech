/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-tekspice-noe.kurata
** File description:
** shell
*/

#ifndef SHELL_HPP_
    #define SHELL_HPP_

#include <iostream>
#include <unordered_map>
#include "Circuit.hpp"

namespace nts {
    class Shell {
        public:
            Shell();
            void runShell(Circuit *circuit);
            void exit();
            void display();
            bool UserInput();
            void simulate();
        private:
            std::unordered_map<std::string, void (Shell::*)()> commands;
            std::string _input;
            size_t _tick = 0;
            Circuit *_parsedcircuit;
    };
}

#endif /* !SHELL_HPP_ */

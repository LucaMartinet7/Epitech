/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD13-luca.martinet
** File description:
** Command
*/

#include "Command.hpp"

void Command::registerCommand(const std::string &name, const std::function<void()> &function)
{
    if (this->command.find(name) != this->command.end())
        throw Error("Already registered command");
    this->command[name] = function;
}

void Command::executeCommand(const std::string &name)
{
    if (this->command.find(name) == this->command.end())
        throw Error("Unknown command");
    this->command[name]();
}

/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD13-luca.martinet
** File description:
** Command
*/

#ifndef COMMAND_HPP_
    #define COMMAND_HPP_

#include <iostream>
#include <functional>
#include <unordered_map>

class Command {
    public:
        class Error : public std::exception {
            public:
                Error(const std::string &message) : message(std::move(message)) {};

                const char*what() const noexcept override
                {
                    return this->message.data();
                }
            private:
                std::string message;
        };

        void registerCommand(const std::string& name, const std::function<void()>& function);
        void executeCommand(const std::string& name);
    protected:
    private:
        std::unordered_map<std::string, std::function<void()>> command;
};

#endif /* !COMMAND_HPP_ */

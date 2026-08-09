/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-raytracer-jules.dufraiche [WSL: Ubuntu]
** File description:
** Error
*/

#ifndef ERROR_HPP_
    #define ERROR_HPP_

#include <iostream>

namespace raytracer {
    class Error : public std::exception {
            public:
                explicit Error(const std::string &message) : _message(std::move(message)) {};
                const char *what() const noexcept override
                {
                    return _message.c_str();
                }
            private:
                std::string _message;
        };
}

#endif /* !ERROR_HPP_ */

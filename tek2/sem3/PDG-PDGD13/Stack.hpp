/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD13-luca.martinet
** File description:
** Stack
*/

#ifndef STACK_HPP_
    #define STACK_HPP_

#include <stack>
#include <string>

class Stack {
    public:
        std::stack<double> stack;
        Stack();
        ~Stack();

        class Error : public std::exception {
            public:
                Error(const std::string &message) : message(move(message)) {};

                const char*what() const noexcept override
                {
                    return this->message.data();
                }
            private:
                std::string message;
        };
        void push(double value);
        double pop();
        double top() const;
        void add();
        void sub();
        void mul();
        void div();
};



#endif /* !STACK_HPP_ */

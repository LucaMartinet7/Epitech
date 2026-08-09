/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD13-luca.martinet
** File description:
** Stack
*/

#include "Stack.hpp"

Stack::Stack() {}

Stack::~Stack() {}

void Stack::push(double value)
{
    this->stack.push(value);
}

double Stack::pop()
{
    if (this->stack.empty())
        throw Error("Empty stack");
    double value = this->stack.top();
    this->stack.pop();
    return value;
}

double Stack::top() const
{
    if (this->stack.empty())
        throw Error("Empty stack");
    return this->stack.top();
}

void Stack::add()
{
    if (this->stack.size() < 2)
        throw Error("Not enough operands");
    double a = this->stack.top();
    this->stack.pop();
    double b = this->stack.top();
    this->stack.pop();
    this->stack.push(a + b);
}

void Stack::sub()
{
    if (this->stack.size() < 2)
        throw Error("Not enough operands");
    double a = this->stack.top();
    this->stack.pop();
    double b = this->stack.top();
    this->stack.pop();
    this->stack.push(a - b);
}

void Stack::mul()
{
    if (this->stack.size() < 2)
        throw Error("Not enough operands");
    double a = this->stack.top();
    this->stack.pop();
    double b = this->stack.top();
    this->stack.pop();
    this->stack.push(a * b);
}

void Stack::div()
{
    if (this->stack.size() < 2)
        throw Error("Not enough operands");
    double a = this->stack.top();
    this->stack.pop();
    double b = this->stack.top();
    this->stack.pop();
    this->stack.push(a / b);
}

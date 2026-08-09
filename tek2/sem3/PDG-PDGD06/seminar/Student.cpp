/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD06-luca.martinet
** File description:
** Student
*/

#include "Student.hpp"
#include <iostream>
#include <regex>
#include <algorithm>

Student::Student(std::string name) : _name(name), _energy(100)
{
    std::cout << "Student " << _name
              << ": I'm ready to learn C++."
              << std::endl;
}

Student::~Student()
{
    std::cout << "Student " << _name
              << ": Wow, much learning today, very smart, such C++."
              << std::endl;
}

bool Student::learn(std::string text)
{
    if (_energy >= 42) {
        _energy -= 42;
        std::cout << "Student " << _name
                  << ": " << text
                  << std::endl;
        return true;
    }
    std::cout << "Student " << _name << ": "
              << std::regex_replace(text, std::regex("C\\+\\+"), "shit")
              << std::endl;
    return false;
}

void Student::drink(std::string name)
{
    if (name == "Red Bull") {
        _energy = std::min(_energy + 32, (unsigned int)100);
        std::cout << "Student " << _name << ": "
            << "Red Bull gives you wings!"
            << std::endl;
    } else if (name == "Monster") {
        _energy = std::min(_energy + 64, (unsigned int)100);
        std::cout << "Student " << _name << ": "
            << "Unleash The Beast!"
            << std::endl;
    } else {
        _energy = std::min(_energy + 1, (unsigned int)100);
        std::cout << "Student " << _name << ": "
            << "ah, yes... enslaved moisture."
            << std::endl;
    }
}

std::string Student::getName(void)
{
    return _name;
}

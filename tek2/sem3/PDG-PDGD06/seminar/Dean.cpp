/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD06-luca.martinet
** File description:
** Dean
*/

#include "Dean.hpp"
#include <iostream>
#include <fstream>
#include <random>
#include <ctime>

Dean::Dean(std::string name) : _name(name), _Active(false)
{
    std::cout << "Dean " + _name
              << ": I'm Dean " + _name + "! How do you do, fellow kids?"
              << std::endl;
}

Dean::~Dean(void)
{
    std::cout << "Dean " << _name
              << ": Time to go home."
              << std::endl;
}

void Dean::teachStudent(Student *student, std::string lesson)
{
    std::string student_name = student->getName();
    std::string choices[5] = {"Cristaline", "Monster", "Evian", "Red Bull", "Sierra Springs"};

    if (!student->learn(lesson)) {
        std::cout << "Dean " << _name
                  << ": All work and no play makes "
                  << student_name
                  << " a dull student."
                  << std::endl;

        std::string randomDrink = choices[std::rand() % 5];
        std::ofstream file(student_name + ".drink");
        file << randomDrink;
        file.close();
    }
}

void Dean::timeCheck(void)
{
    _Active = !_Active;

    if (_Active) {
        std::cout << "Dean " << _name
                  << ": Where is everyone?"
                  << std::endl;
    } else {
        std::cout << "Dean " << _name
                  << ": Don't forget to close the windows when you leave."
                  << std::endl;
    }
}

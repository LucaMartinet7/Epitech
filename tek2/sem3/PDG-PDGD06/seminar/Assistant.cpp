/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD06-luca.martinet
** File description:
** Assistant
*/

#include "Assistant.hpp"
#include <iostream>
#include <fstream>

Assistant::Assistant(int id) : _id(id), _Active(false)
{
    std::cout << "Assistant " << _id
              << ": 'morning everyone *sip coffee*"
              << std::endl;
}

Assistant::~Assistant(void)
{
    std::cout << "Assistant " << _id
              << ": see you tomorrow at 9.00 *sip coffee*"
              << std::endl;
}

void Assistant::giveDrink(Student *student, std::string name)
{
    std::cout << "Assistant " << _id
              << ": drink this, " + student->getName() + " *sip coffee*"
              << std::endl;
    student->drink(name);
}

std::string Assistant::readDrink(std::string st_name)
{
    std::ifstream infile;
    std::string drink;

    infile.open(st_name + ".drink");

    if (!infile.good())
        return ("");

    std::getline(infile, drink);
    std::cout << "Assistant " << _id
              << ": " + st_name + " needs a "
              << drink
              << " *sip coffee*"
              << std::endl;
    remove((st_name + ".drink").c_str());
    return drink;
}

void Assistant::helpStudent(Student *student)
{
    std::string st_name = student->getName();
    std::string drink = readDrink(st_name);

    if (drink == "") {
         std::cout << "Assistant " << _id
                   << ": " + st_name + " seems fine *sip coffee*"
                   << std::endl;
    } else {
        giveDrink(student, drink);
    }
}

void Assistant::timeCheck(void)
{
    _Active = !_Active;

    if (_Active) {
        std::cout << "Assistant " << _id
                  << ": Time to teach some serious business *sip coffee*"
                  << std::endl;
    } else {
        std::cout << "Assistant " << _id
                  << ": Enough teaching for today *sip coffee*"
                  << std::endl;
    }
}

int Assistant::getId(void)
{
    return _id;
}

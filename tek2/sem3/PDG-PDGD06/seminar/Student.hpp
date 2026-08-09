/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD06-luca.martinet
** File description:
** Student
*/

#ifndef STUDENT_HPP_
    #define STUDENT_HPP_

#include <string>

class Student {
    public:
        Student(const std::string name);
        ~Student();

        bool learn(std::string text);
        void drink(std::string name);
        std::string getName(void);

    protected:
    private:
    std::string _name;
    unsigned int _energy;
};

#endif /* !STUDENT_HPP_ */

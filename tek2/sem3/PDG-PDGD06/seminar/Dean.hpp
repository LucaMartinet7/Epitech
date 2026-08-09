/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD06-luca.martinet
** File description:
** Dean
*/

#ifndef DEAN_HPP_
    #define DEAN_HPP_

#include "Student.hpp"

class Dean {
    public:
        Dean(std::string name);
        ~Dean();

        std::string getName(void);
        void teachStudent(Student *student, std::string lesson);
        void timeCheck(void);

    protected:
    private:
    std::string _name;
    bool _Active;
};

#endif /* !DEAN_HPP_ */

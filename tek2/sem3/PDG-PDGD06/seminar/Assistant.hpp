/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD06-luca.martinet
** File description:
** Assistant
*/

#ifndef ASSISTANT_HPP_
    #define ASSISTANT_HPP_

#include "Student.hpp"

class Assistant {
    public:
        Assistant(int id);
        ~Assistant();

        void giveDrink(Student *student, std::string name);
        std::string readDrink(std::string st_name);
        void helpStudent(Student *student);
        void timeCheck(void);
        int getId(void);
    protected:
    private:
    int _id;
    bool _Active;
};

#endif /* !ASSISTANT_HPP_ */

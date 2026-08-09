/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD07pm-luca.martinet
** File description:
** Skat
*/

#ifndef SKAT_HPP_
    #define SKAT_HPP_

#include <string>
class Skat {
    public:
        Skat(const std::string &name = "bob", int stimPaks = 15);
        ~Skat();
        int &stimPaks();

        const std::string &name();
        void shareStimPaks(int number, int &stock);
        void addStimPaks(unsigned int number);
        void useStimPaks();
        void status() const;

    private:
        const std::string _name;
        int _stock;
};
#endif /* !SKAT_HPP_ */

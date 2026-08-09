/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD12-luca.martinet
** File description:
** Toy
*/

#ifndef TOY_HPP_
    #define TOY_HPP_

#include "Picture.hpp"
#include <string>

class Toy {
    public:
        enum ToyType {
            BASIC_TOY,
            ALIEN,
            BUZZ,
            WOODY
        };

        Toy();
        Toy(ToyType type, const std::string &name, const std::string &file);
        Toy(const Toy &other);
        ~Toy();
        Toy &operator=(const Toy &other);

        ToyType getType() const;
        std::string getName() const;
        void setName(const std::string &name);
        bool setAscii(const std::string &file);
        std::string getAscii() const;

        virtual void speak(const std::string &statement);
        Toy &operator<<(const std::string &str);

    protected:
    private:
        ToyType type;
        std::string name;
        Picture picture;
};

std::ostream &operator<<(std::ostream &os, const Toy &toy);

#endif /* !TOY_HPP_ */

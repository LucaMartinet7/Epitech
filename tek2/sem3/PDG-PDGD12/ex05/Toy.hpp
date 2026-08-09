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

        virtual bool speak(const std::string &statement);
        virtual bool speak_es(const std::string &statement);

        Toy &operator<<(const std::string &str);

        class Error {
            public:
                enum ErrorType {
                    UNKNOWN,
                    PICTURE,
                    SPEAK
                };
                std::string what() const noexcept;
                std::string where() const noexcept;
                ErrorType type;
                explicit Error(ErrorType type = UNKNOWN, std::string what = "", std::string where = "");
            private:
                std::string _what;
                std::string _where;
        };

        const Error &getLastError() const noexcept;

    protected:
        ToyType type;
        std::string name;
        Picture picture;
        Error error = Error();
};

std::ostream &operator<<(std::ostream &os, const Toy &toy);

#endif /* !TOY_HPP_ */

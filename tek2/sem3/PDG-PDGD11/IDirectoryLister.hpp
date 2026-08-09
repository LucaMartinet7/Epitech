/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD11-luca.martinet
** File description:
** IDirectoryLister
*/

#ifndef IDIRECTORYLISTER_HPP_
    #define IDIRECTORYLISTER_HPP_

#include <string>

class IDirectoryLister{
    public:
        virtual bool open(const std::string &path, bool hidden) = 0;
        virtual std::string get() = 0;
        class OpenFailureException : public std::exception {
            public:
                const char *what() const noexcept override;
        };
        class NoMoreFileException : public std::exception {
            public:
                const char *what() const noexcept override;
        };
    protected:
    private:
};

#endif /* !IDIRECTORYLISTER_HPP_ */

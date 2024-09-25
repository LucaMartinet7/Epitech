/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-tekspice-noe.kurata
** File description:
** Throws
*/

#ifndef THROWS_HPP_
#define THROWS_HPP_

#include <exception>
#include <string>

#define NEW_EXCEPTION(name)                                                        \
    class name : public NtsException                                               \
    {                                                                              \
    public:                                                                        \
        name(std::string const &message, std::string const &type = #name) noexcept \
            : NtsException(message, type) {}                                       \
    };

namespace nts
{
    class NtsException : public std::exception
    {
    public:
        NtsException(std::string const &message, std::string const &type = "Unknown") noexcept
        {
            _message = message;
            _type = type;
        }

        std::string const &getType() const { return _type; }
        const char *what() const noexcept override { return _message.c_str(); }

    private:
        std::string _message;
        std::string _type;
    };

    //parse
    NEW_EXCEPTION(InvalidFileException)
    NEW_EXCEPTION(MissingSectionException)
    //factory
    NEW_EXCEPTION(InvalidComponentTypeException)
    //shell
    NEW_EXCEPTION(InvalidCommandException)
    //circuit
    NEW_EXCEPTION(InvalidPinException)
    //component
    NEW_EXCEPTION(NoPinFoundExceptioin)
    NEW_EXCEPTION(PinAlreadyLinkedException)

}

#endif /* !THROWS_HPP_ */

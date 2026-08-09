#pragma once

#include <exception>
#include <string>

#define NEW_EXCEPTION(name)                                                        \
    class name : public RType::NtsException                                        \
    {                                                                              \
    public:                                                                        \
        name(std::string const &message, std::string const &type = #name) noexcept \
            : RType::NtsException(message, type) {}                                \
    };

namespace RType
{
    class NtsException : public std::exception
    {
    public:
        NtsException(std::string const &message, std::string const &type = "Unknown") noexcept
            : _message(message), _type(type) {}

        std::string const &getType() const { return _type; }
        const char *what() const noexcept override { return _message.c_str(); }

    private:
        std::string _message;
        std::string _type;
    };

    // Parsing exceptions
    NEW_EXCEPTION(InvalidPortException)
    NEW_EXCEPTION(InvalidArgumentException)

    // Network exceptions
    NEW_EXCEPTION(NetworkException)
    NEW_EXCEPTION(ConnectionFailedException)
    NEW_EXCEPTION(TimeoutException)

    // General exceptions
    NEW_EXCEPTION(StandardException)
    NEW_EXCEPTION(UnknownException)
    NEW_EXCEPTION(PermissionDeniedException)
    NEW_EXCEPTION(NotImplementedException)
}
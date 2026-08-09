/*
** EPITECH PROJECT, 2024
** paradigms day13
** File description:
** IModule.hpp
*/

#ifndef _IMODULE_HPP
    #define _IMODULE_HPP

#include <string>

namespace Krell {
    class IModule {
    public:
        virtual ~IModule() {};

        virtual std::string getName() const = 0;
        virtual std::string getData() const = 0;
        virtual void retrieveData() = 0;
        virtual void update() = 0;
    };
};

#endif /* !_IMODULE_HPP */
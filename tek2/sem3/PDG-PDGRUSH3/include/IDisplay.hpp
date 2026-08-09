/*
** EPITECH PROJECT, 2024
** paradigms day13
** File description:
** IDisplay.hpp
*/

#ifndef _IDISPLAY_HPP
    #define _IDISPLAY_HPP

#include <string>

#include "IModule.hpp"

namespace Krell {
    class IDisplay {
    public:
        virtual ~IDisplay() {};

        virtual void show(int width) = 0;
        virtual void update(IModule* updatedModule) = 0;
        virtual void setModule(IModule* module) = 0;
    };

}

#endif /* !_IDISPLAY_HPP */

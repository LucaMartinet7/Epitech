/*
** EPITECH PROJECT, 2024
** paradigms day13
** File description:
** DateTimeModule.hpp
*/

#ifndef _CLOCKMODULE_HPP
    #define _CLOCKMODULE_HPP

#include "IModule.hpp"

namespace Krell {

    class ClockModule : public IModule {
    public:
        ClockModule();
        ~ClockModule() override;

        std::string getName() const override;
        std::string getData() const override;
        void retrieveData() override;
        void update() override;

    private:
        const std::string _name;
        std::string _currentDateTime;
        std::string _data;
    };

}

#endif /* !_CLOCKMODULE_HPP */

/*
** EPITECH PROJECT, 2024
** paradigms day13
** File description:
** RAMModule.hpp
*/

#ifndef _RAMMODULE_HPP
    #define _RAMMODULE_HPP

#include "IModule.hpp"

namespace Krell {

    class RAMModule : public IModule {
    public:
        RAMModule();
        ~RAMModule() override;

        std::string getName() const override;
        std::string getData() const override;
        void retrieveData() override;
        void update() override;

    private:
        const std::string _name;
        unsigned int _percentage;
        unsigned int _total;
        unsigned int _free;
        std::string _data;
    };

}

#endif /* !_RAMMODULE_HPP */

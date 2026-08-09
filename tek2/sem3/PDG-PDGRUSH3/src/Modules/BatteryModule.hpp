/*
** EPITECH PROJECT, 2024
** paradigms day13
** File description:
** BatteryModule.hpp
*/

#ifndef _BATTERYMODULE_HPP
    #define _BATTERYMODULE_HPP

#include "IModule.hpp"

#include <fstream>

namespace Krell {

    class BatteryModule : public IModule {
    public:
        BatteryModule();
        ~BatteryModule() override;

        std::string getName() const override;
        std::string getData() const override;
        void retrieveData() override;
        void update() override;
    private:
        const std::string _name;
        unsigned int _capacity;
        std::string _status;
        std::string _data;
    };

}

#endif /* !_BATTERYMODULE_HPP */

/*
** EPITECH PROJECT, 2024
** paradigms day13
** File description:
** BatteryModule.cpp
*/

#include <iostream>

#include "BatteryModule.hpp"


namespace Krell {

    BatteryModule::BatteryModule(void) : _name("Battery Module"), _data("Unknown")
    {
        return;
    }

    BatteryModule::~BatteryModule(void)
    {
        return;
    }

    std::string BatteryModule::getName(void) const
    {
       return this->_name;
    }

    std::string BatteryModule::getData(void) const
    {
        if (this->_data != std::string("Unknown"))
            return std::to_string(this->_capacity) + "%, " + "state: " + this->_status;
        return "Unknown";
    }

    void BatteryModule::retrieveData(void)
    {
        std::ifstream batteryFile("/sys/class/power_supply/BAT0/capacity");
        std::ifstream statusFile("/sys/class/power_supply/BAT0/status");

        if (batteryFile.is_open()) {
            batteryFile >> this->_capacity;
            batteryFile.close();
        } else
            this->_data = "Unknown";

        if (statusFile.is_open()) {
            statusFile >> this->_status;
            statusFile.close();
        } else
            this->_data = "Unknown";
    }

    void BatteryModule::update(void)
    {
        this->_data = "";
        this->retrieveData();
    }
}

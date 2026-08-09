/*
** EPITECH PROJECT, 2024
** paradigms day13
** File description:
** DateTimeModule.cpp
*/

#include <iostream>
#include <ctime>

#include "DateTimeModule.hpp"

namespace Krell {

    ClockModule::ClockModule(void) : _name("Date and time Module"), _data("Unknown")
    {
        return;
    }

    ClockModule::~ClockModule(void)
    {
        return;
    }

    std::string ClockModule::getName(void) const
    {
       return this->_name;
    }

    std::string ClockModule::getData(void) const
    {
        if (this->_data != std::string("Unknown"))
            return "Time: " + this->_currentDateTime;
        return "Unknown";
    }

    void ClockModule::retrieveData(void)
    {
        std::time_t currentTime = std::time(nullptr);
        std::tm* localTime = std::localtime(&currentTime);
        char buffer[80];

        if (std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime) > 0)
            this->_currentDateTime = std::string(buffer);
        else
            this->_data = "Unknown";
    }

    void ClockModule::update(void)
    {
        this->_data = "";
        this->retrieveData();
    }

}

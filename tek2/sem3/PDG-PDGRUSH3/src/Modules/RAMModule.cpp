/*
** EPITECH PROJECT, 2024
** paradigms day13
** File description:
** RAMModule.cpp
*/

#include <iostream>
#include <sys/sysinfo.h>

#include "RAMModule.hpp"

namespace Krell {

    RAMModule::RAMModule(void) : _name("RAM Module"), _data("Unknown")
    {
        return;
    }

    RAMModule::~RAMModule(void)
    {
        return;
    }

    std::string RAMModule::getName(void) const
    {
       return this->_name;
    }

    std::string RAMModule::getData(void) const
    {
        return this->_data;
    }

    void RAMModule::retrieveData(void)
    {
        struct sysinfo memInfo;
        sysinfo(&memInfo);

        this->_total = memInfo.totalram / 1024 / 1024;
        this->_free = memInfo.freeram / 1024 / 1024;
        this->_percentage = ((this->_total - this->_free) * 100) / this->_total;

        _data = "Total Memory: " + std::to_string(this->_total) + " MB, Free Memory: " + std::to_string(this->_free) + " MB, Usage Percentage: " + std::to_string(this->_percentage) + "%";
    }

    void RAMModule::update(void)
    {
        this->_data = "";
        this->retrieveData();
    }
}

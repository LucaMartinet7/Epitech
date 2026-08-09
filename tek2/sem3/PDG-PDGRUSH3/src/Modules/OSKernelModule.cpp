/*
** EPITECH PROJECT, 2024
** paradigms day13
** File description:
** OSKernelModule.cpp
*/

#include <iostream>
#include <sys/utsname.h>

#include "OSKernelModule.hpp"

namespace Krell {

    OSKernelModule::OSKernelModule(void) : _name("OS-Kernel Module"), _data("Unknown")
    {
        return;
    }

    OSKernelModule::~OSKernelModule(void)
    {
        return;
    }

    std::string OSKernelModule::getName(void) const
    {
       return this->_name;
    }

    std::string OSKernelModule::getData(void) const
    {
        if (this->_data != std::string("Unknown"))
            return "Op. sys.: " + this->_osName + ", Kernel: " + this->_kernelVersion;
        return "Unknown";
    }

    void OSKernelModule::retrieveData(void)
    {
        struct utsname systemInfo;
        if (uname(&systemInfo) == 0) {
            this->_osName = systemInfo.sysname;
            this->_kernelVersion = systemInfo.release;
        } else
           this->_data = "Unknown";
    }

    void OSKernelModule::update(void)
    {
        this->_data = "";
        this->retrieveData();
    }

}

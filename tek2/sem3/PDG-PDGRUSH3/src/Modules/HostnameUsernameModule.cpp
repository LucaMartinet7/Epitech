/*
** EPITECH PROJECT, 2024
** paradigms day13
** File description:
** HostnameUsernameModule.cpp
*/

#include <iostream>
#include <unistd.h>
#include <limits.h>

#include "HostnameUsernameModule.hpp"

namespace Krell {

    HostUserModule::HostUserModule(void) : _name("Hostname and Username Module"), _data("Unknown")
    {
        return;
    }

    HostUserModule::~HostUserModule(void)
    {
        return;
    }

    std::string HostUserModule::getName(void) const
    {
       return this->_name;
    }

    std::string HostUserModule::getData(void) const
    {
        if (this->_data != std::string("Unknown"))
            return "Username: " + this->_username + ", Hostname: " + this->_hostname;
        return "Unknown";
    }

    void HostUserModule::retrieveData(void)
    {
        char hostBuffer[HOST_NAME_MAX];
        char userBuffer[LOGIN_NAME_MAX];

        if (gethostname(hostBuffer, sizeof(hostBuffer)) == 0)
            this->_hostname = std::string(hostBuffer);
        else
            this->_data = "Unknown";
        if (getlogin_r(userBuffer, sizeof(userBuffer)) == 0)
            this->_username = std::string(userBuffer);
        else
            this->_data = "Unknown";
    }

    void HostUserModule::update(void)
    {
        this->_data = "";
        this->retrieveData();
    }

}

/*
** EPITECH PROJECT, 2024
** paradigms day13
** File description:
** HostnameUsernameModule.hpp
*/

#ifndef _HOSTUSERMODULE_HPP
    #define _HOSTUSERMODULE_HPP

#include "IModule.hpp"

namespace Krell {

    class HostUserModule : public IModule {
    public:
        HostUserModule();
        ~HostUserModule() override;

        std::string getName() const override;
        std::string getData() const override;
        void retrieveData() override;
        void update() override;

    private:
        const std::string _name;
        std::string _username;
        std::string _hostname;
        std::string _data;
    };

}

#endif /* !_HOSTUSERMODULE_HPP */

/*
** EPITECH PROJECT, 2024
** paradigms day13
** File description:
** OSKernelModule.hpp
*/

#ifndef _OSKERNELMODULE_HPP
    #define _OSKERNELMODULE_HPP

#include "IModule.hpp"

namespace Krell {

    class OSKernelModule : public IModule {
    public:
        OSKernelModule();
        ~OSKernelModule() override;

        std::string getName() const override;
        std::string getData() const override;
        void retrieveData() override;
        void update() override;

    private:
        const std::string _name;
        std::string _osName;
        std::string _kernelVersion;
        std::string _data;
    };

}

#endif /* !_OSKERNELMODULE_HPP */

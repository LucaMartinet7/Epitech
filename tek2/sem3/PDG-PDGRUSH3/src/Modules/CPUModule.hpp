/*
** EPITECH PROJECT, 2024
** paradigms day13
** File description:
** CPUModule.hpp
*/

#ifndef _CPUMODULE_HPP
    #define _CPUMODULE_HPP

#include <vector>

#include "IModule.hpp"

namespace Krell {

    class CPUModule : public IModule {
    public:
        CPUModule();
        ~CPUModule() override;

        std::string getName() const override;
        std::string getData() const override;
        void retrieveData() override;
        void update() override;

    private:
        void getCore();
        const std::string _name;

        struct CoreInfo {
            std::string model;
            double frequency;
        };

        std::vector<CoreInfo> _coreInfoList;
        double _globalFrequency;
        int _numPhysicalCPUs;
        int _numVirtualCPUs;
        std::string _data;
    };

}

#endif /* !_CPUMODULE_HPP */

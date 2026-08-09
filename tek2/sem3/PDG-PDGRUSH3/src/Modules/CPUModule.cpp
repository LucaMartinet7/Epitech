/*
** EPITECH PROJECT, 2024
** paradigms day13
** File description:
** CPUModule.cpp
*/

#include <iostream>
#include <fstream>
#include <sstream>

#include "CPUModule.hpp"

namespace Krell {

    CPUModule::CPUModule(void) : _name("CPU Module"), _data("Unknown")
    {
        return;
    }

    CPUModule::~CPUModule(void)
    {
        return;
    }

    std::string CPUModule::getName(void) const
    {
       return this->_name;
    }

    std::string CPUModule::getData(void) const
    {
        if (!this->_coreInfoList.empty()) {
            std::ostringstream dataStream;
            dataStream << "Global Frequency: " << this->_globalFrequency << " GHz, Physical CPUs: " << this->_numPhysicalCPUs << ", Virtual CPUs: " << this->_numVirtualCPUs << "\n\n";

            for (std::size_t i = 0; i < this->_coreInfoList.size(); ++i)
                dataStream << "Core " << i << " - Model: " << this->_coreInfoList[i].model << ", Frequency: " << this->_coreInfoList[i].frequency << " GHz\n";

            return dataStream.str();
        }
        return "Unknown";
    }

    void CPUModule::getCore(void)
    {
        std::ifstream coreInfoFile("/proc/cpuinfo");
        CoreInfo currentCore;
        std::string line;

        while (std::getline(coreInfoFile, line)) {
            if (line.find("processor") != std::string::npos) {
                if (!currentCore.model.empty()) {
                    this->_coreInfoList.push_back(currentCore);
                    currentCore = CoreInfo();
                }
            } else if (line.find("model name") != std::string::npos) {
                std::size_t pos = line.find(':');
                if (pos != std::string::npos) {
                    currentCore.model = line.substr(pos + 2);
                }
            } else if (line.find("cpu MHz") != std::string::npos) {
                std::size_t pos = line.find(':');
                if (pos != std::string::npos) {
                    std::istringstream iss(line.substr(pos + 2));
                    iss >> currentCore.frequency;
                    currentCore.frequency /= 1000.0;
                }
            }
        }
        if (!currentCore.model.empty()) {
            this->_coreInfoList.push_back(currentCore);
        }
        coreInfoFile.close();
    }

    void CPUModule::retrieveData(void)
    {
        this->_coreInfoList.clear();

        std::ifstream globalInfoFile("/proc/cpuinfo");
        std::string line;

        while (std::getline(globalInfoFile, line)) {
            if (line.find("cpu MHz") != std::string::npos) {
                std::size_t pos = line.find(':');
                if (pos != std::string::npos) {
                    std::istringstream iss(line.substr(pos + 2));
                    iss >> this->_globalFrequency;
                    this->_globalFrequency /= 1000.0;
                }
            } else if (line.find("physical id") != std::string::npos) {
                std::size_t pos = line.find(':');
                if (pos != std::string::npos) {
                    std::istringstream iss(line.substr(pos + 2));
                    iss >> this->_numPhysicalCPUs;
                    ++this->_numPhysicalCPUs;

                }
            } else if (line.find("processor") != std::string::npos) {
                std::size_t pos = line.find(':');
                if (pos != std::string::npos) {
                    std::istringstream iss(line.substr(pos + 2));
                    iss >> this->_numVirtualCPUs;
                }
            }
        }
        globalInfoFile.close();
        this->getCore();
    }

    void CPUModule::update(void)
    {
        this->retrieveData();
    }
}

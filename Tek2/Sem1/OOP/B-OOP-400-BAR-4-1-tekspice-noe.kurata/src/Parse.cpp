/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-tekspice-noe.kurata
** File description:
** parse
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "AComponent.hpp"
#include "Parse.hpp"
#include "Factory.hpp"
#include "Circuit.hpp"
#include "Throws.hpp"

namespace nts {
    Parse::Parse() {}

    std::string Parse::processLine(const std::string line)
    {
        return std::regex_replace(line, std::regex("#.*"), "");
    }

    bool fileExistsEmpty(const std::string &filePath)
    {
        std::ifstream file(filePath);
        return file.peek() == std::ifstream::traits_type::eof();
    }



    Circuit Parse::parseFile(const std::string &filePath)
    {
        bool ChipSection = false;
        bool LinkSection = false;
        size_t sections = 0;
        std::string line;
        std::ifstream file(filePath);
        Circuit _circuit;

        if (fileExistsEmpty(filePath))
            throw InvalidFileException("File is empty");

        while (std::getline(file, line)) {
            std::string processedLine = processLine(line);
            processedLine = trim(processedLine);
            if (!processedLine.empty()) {
                if (processedLine.find(".chipsets:") != std::string::npos) {
                    ChipSection = true;
                    LinkSection = false;
                    sections++;
                } else if (processedLine.find(".links:") != std::string::npos) {
                    ChipSection = false;
                    LinkSection = true;
                    sections++;
                } else if (ChipSection) {
                    std::string type = processedLine.substr(0, processedLine.find(' '));
                    std::string name = processedLine.substr(processedLine.find(' ') + 1);
                    _circuit.createComponent(type, name);
                } else if (LinkSection) {
                    std::string name1 = processedLine.substr(0, processedLine.find(':'));
                    std::size_t startOfPin1 = processedLine.find(':') + 1;
                    std::size_t endOfPin1 = processedLine.find(' ');
                    std::string pin1 = processedLine.substr(startOfPin1, endOfPin1 - startOfPin1);
                    std::string name2 = processedLine.substr(endOfPin1 + 1, processedLine.find_last_of(':') - endOfPin1 - 1);
                    std::string pin2 = processedLine.substr(processedLine.find_last_of(':') + 1);
                }
            }
        }
        if (sections != 2)
            throw MissingSectionException("Missing Section in file");
        return _circuit;
    }
}
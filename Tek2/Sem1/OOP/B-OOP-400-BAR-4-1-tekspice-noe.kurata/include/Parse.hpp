/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-tekspice-noe.kurata
** File description:
** parse
*/

#ifndef PARSE_HPP_
#define PARSE_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include "Circuit.hpp"

namespace nts {
    static inline std::string trim(std::string str)
    {
        return std::regex_replace(str, std::regex("^\\s+|\\s+$"), "");
    }
    class Parse {
        public:
            Parse();
            std::string processLine(const std::string line);
            Circuit parseFile(const std::string &filePath);
            Circuit &getCircuit();
            void displayCircuit() const;
    };
}

#endif /* !PARSE_HPP_ */

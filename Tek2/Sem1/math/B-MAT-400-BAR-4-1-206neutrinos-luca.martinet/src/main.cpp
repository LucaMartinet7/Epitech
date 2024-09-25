/*
** EPITECH PROJECT, 2024
** B-MAT-400-BAR-4-1-206neutrinos-luca.martinet [WSL: Ubuntu]
** File description:
** main
*/

#include <iostream>

#include "neutrinos.hpp"

int main(int argc, char **argv)
{
    try {
        if (argc == 2) {
            if (std::string(argv[1]) == "-h") {
                manHelp();
            } else {
                throw BadArgumentError("Invalid number of parameters, please repeat with '-h'");
            }
        } else if (argc == 5) {
            Neutrinos obj(std::stoi(argv[1]), std::stoi(argv[2]), std::stoi(argv[3]), std::stoi(argv[4]));
            loop(obj);
        } else {
            throw BadArgumentError("Invalid number of parameters, please repeat with '-h'");
        }
    } catch (const std::exception& error) {
        std::cerr << error.what() << std::endl;
        exit(84);
    }
    return 0;
}

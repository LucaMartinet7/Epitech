/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-tekspice-noe.kurata
** File description:
** main
*/

#include <iostream>
#include <stdexcept>
#include <iostream>
#include <cstring>
#include "Throws.hpp"
#include "Parse.hpp"
#include "Factory.hpp"
#include "Shell.hpp"

static void help()
{
    std::cout << "Usage:\n\t./nanotekspice config.nts" << std::endl
              << "\nconfig.nts:\n\tPath to the configuration file with chipsets and links." << std::endl;
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Invalid number of arguments." << std::endl;
        return 84;
    }
    if (std::string(av[1]) == "-h" || std::string(av[1]) == "--help") {
        help();
        return 0;
    }
    nts::Parse parser;
    nts::Shell shell;
    nts::Circuit parsedcircuit;
    try {
        parsedcircuit = parser.parseFile(av[1]);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    };
    shell.runShell(&parsedcircuit);
    return 0;
}
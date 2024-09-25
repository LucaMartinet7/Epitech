/*
** EPITECH PROJECT, 2024
** B-MAT-400-BAR-4-1-209poll-luca.martinet
** File description:
** main
*/

#include "poll.hpp"

void help(void)
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t./209poll pSize sSize p" << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\tpSize\tsize of the population" << std::endl;
    std::cout << "\tsSize\tsize of the sample (supposed to be representative)" << std::endl;
    std::cout << "\tp\tpercentage of voting intentions for a specific candidate" << std::endl;
}

bool check_args(int pSize, int sSize, double p)
{
    if (pSize <= 1)
        throw std::invalid_argument("pSize must be greater than 1");
    if (sSize <= 0 || sSize > pSize)
        throw std::invalid_argument("sSize must be between 1 and pSize");
    if (p < 0 || p > 100)
        throw std::invalid_argument("p must be between 0 and 100");
    return true;
}

int main(int ac, char **av)
{
    try {
        if (ac != 4)
            throw std::invalid_argument("Invalid number of arguments");
        if (std::string(av[1]) == "-h" || std::string(av[1]) == "--help") {
            help();
            return 0;
        }
        int pSize, sSize;
        double p;
        try {
            pSize = std::stoi(av[1]);
            sSize = std::stoi(av[2]);
            p = std::stod(av[3]);
        } catch (std::invalid_argument &e) {
            throw std::invalid_argument("Invalid argument: " + std::string(e.what()));
        }
        check_args(pSize, sSize, p);
        print_result(pSize, sSize, p);
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}

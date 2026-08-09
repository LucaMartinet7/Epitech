/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD06-luca.martinet
** File description:
** MyCat
*/

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    if (argc == 1) {
        std::string line;
        while (std::getline(std::cin, line))
            std::cout << line << std::endl;
    } else {
        int a = 1;
        while (a < argc) {
            std::ifstream file(argv[a]);
            if (file.is_open()) {
                std::string line;
                while (std::getline(file, line))
                    std::cout << line << std::endl;
                file.close();
                a = a + 1;
            } else {
                std::cerr << "MyCat: " << argv[a] << ": No such file or directory" << std::endl;
                exit(84);
            }
        }
    }
    return 0;
}


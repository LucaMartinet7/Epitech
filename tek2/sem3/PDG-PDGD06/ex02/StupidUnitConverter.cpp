/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD06-luca.martinet
** File description:
** StupidUnitConverter
*/

#include <iostream>
#include <iomanip>
#include <sstream>

int main(int argc, char **argv)
{
    std::string truc;
    float temp;
    std::string unit;

    while (getline(std::cin, truc)) {
        std::stringstream ss(truc);
        ss >> temp >> unit;

        if (unit == "Fahrenheit") {
            std::cout << std::setw(16) << std::fixed << std::setprecision(3) << 5.0 / 9.0 * (temp - 32)
                      << std::setw(16) << " Celsius"
                      << std::endl;
        } else if (unit == "Celsius") {
            std::cout << std::setw(16) << std::fixed << std::setprecision(3) << temp * 9.0 / 5.0 + 32
                      << std::setw(16) << " Fahrenheit"
                      << std::endl;
        }
    }
}

/*
** EPITECH PROJECT, 2024
** B-MAT-400-BAR-4-1-206neutrinos-luca.martinet [WSL: Ubuntu]
** File description:
** loop
*/

#include <iostream>

#include "neutrinos.hpp"

void manHelp()
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t./206neutrinos n a h sd" << std::endl;
    std::cout << "\nDESCRIPTION" << std::endl;
    std::cout << "\tn\tnumber of values" << std::endl;
    std::cout << "\ta\tarithmetic mean" << std::endl;
    std::cout << "\th\tharmonic mean" << std::endl;
    std::cout << "\tsd\tstandard deviation" << std::endl;
}

void loop(Neutrinos& obj)
{
    while (true) {
        std::cout << "Enter next value: ";
        std::string input_str;
        std::cin >> input_str;
        if (input_str == "END")
            exit(0);
        double index = std::stod(input_str);
        obj.setValue();
        obj.getRootMean(index);
        obj.getStandardDeviation(index);
        obj.getArithmeticMean(index);
        obj.getHarmonicMean(index);
        obj.printValue();
    }
}

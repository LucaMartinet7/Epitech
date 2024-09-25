/*
** EPITECH PROJECT, 2024
** B-MAT-400-BAR-4-1-206neutrinos-luca.martinet
** File description:
** 206neutrinos
*/

#include <iostream>
#include <iomanip>
#include <cmath>

#include "neutrinos.hpp"

Neutrinos::Neutrinos(double value, double arithmetic, double harmonic, double average) : value(value), arithmetic(arithmetic), harmonic(harmonic), average(average), root(0)
{
    if (value < 0 || arithmetic < 0 || harmonic < 0 || average < 0)
        throw BadArgumentError("You must pass positive arguments");
}

void Neutrinos::setValue()
{
    value += 1;
}

void Neutrinos::getStandardDeviation(double index)
{
    average = std::sqrt((((std::pow(average, 2) + std::pow(arithmetic, 2)) * (value - 1) + std::pow(index, 2)) / value) - std::pow(((arithmetic * (value - 1)) + index) / value, 2));
}

void Neutrinos::getArithmeticMean(double index)
{
    arithmetic = ((arithmetic * (value - 1)) + index) / value;
}

void Neutrinos::getRootMean(double index)
{
    root = std::sqrt((((std::pow(average, 2) + std::pow(arithmetic, 2)) * (value - 1)) + std::pow(index, 2)) / value);
}

void Neutrinos::getHarmonicMean(double index)
{
    harmonic = value / (((1 / harmonic) * (value - 1)) + (1 / index));
}

double Neutrinos::getArithmetic() const
{
    double result = arithmetic;
    return result;
}

double Neutrinos::getHarmonic() const
{
    double result = harmonic;
    return result;
}

double Neutrinos::getAverage() const
{
    double result = average;
    return result;
}

double Neutrinos::getRoot() const
{
    double result = root;
    return result;
}

double Neutrinos::getValue() const
{
    double result = value;
    return result;
}

void Neutrinos::printValue()
{
    std::cout << "\tNumber of values:\t" << std::fixed << std::setprecision(0) << value << std::endl;
    std::cout << "\tStandard deviation:\t" << std::fixed << std::setprecision(2) << average << std::endl;
    std::cout << "\tArithmetic mean:\t" << std::fixed << std::setprecision(2) << arithmetic << std::endl;
    std::cout << "\tRoot mean square:\t" << std::fixed << std::setprecision(2) << root << std::endl;
    std::cout << "\tHarmonic mean:\t\t" << std::fixed << std::setprecision(2) << harmonic << std::endl << std::endl;
}

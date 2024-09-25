/*
** EPITECH PROJECT, 2024
** B-MAT-400-BAR-4-1-209poll-luca.martinet
** File description:
** 209poll
*/

#include "poll.hpp"

double get_variance(int pSize, int sSize, double p)
{
    return (static_cast<double>(p) * (1 - p) / sSize) * ((static_cast<double>(pSize) - sSize) / (pSize - 1));
}

void print_result(int pSize, int sSize, double p)
{
    double p_percentage = p / 100.0;
    double variance = get_variance(pSize, sSize, (p_percentage));
    std::cout << "Population size: \t\t" << pSize << std::endl;
    std::cout << "Sample size: \t\t\t" << sSize << std::endl;
    std::cout << "Voting intentions: \t\t" << p << "%" << std::endl;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Variance: \t\t\t" << variance << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "95% confidence interval: \t[" << (p_percentage - 1.96 * std::sqrt(variance)) * 100 << "%; " << (p_percentage + 1.96 * std::sqrt(variance)) * 100 << "%]" << std::endl;
    std::cout << "99% confidence interval: \t[" << (p_percentage - 2.58 * std::sqrt(variance)) * 100 << "%; " << (p_percentage + 2.58 * std::sqrt(variance)) * 100 << "%]" << std::endl;
}

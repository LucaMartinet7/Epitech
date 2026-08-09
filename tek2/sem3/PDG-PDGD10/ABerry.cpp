/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD10-luca.martinet
** File description:
** ABerry
*/

#include "ABerry.hpp"
#include <utility>

ABerry::ABerry(const std::string& name, unsigned int vitamins) : AFruit(name, vitamins, true) {}

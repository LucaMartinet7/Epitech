/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD10-luca.martinet
** File description:
** Orange
*/

#include "Orange.hpp"
#include <iostream>

Orange::Orange() : ACitrus("orange", 7) {}

Orange::Orange(std::string name, unsigned int vitamins) : ACitrus(name, vitamins) {}

/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD05-luca.martinet
** File description:
** ex3
*/

#include "string.h"

char at(const string_t *this, size_t pos)
{
    if (this == NULL || this->str == NULL || pos >= strlen(this->str))
        return -1;
    return this->str[pos];
}

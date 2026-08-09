/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD05-luca.martinet
** File description:
** ex9
*/

#include "string.h"

int empty(const string_t *this)
{
    if (this == NULL || this->str == NULL)
        return 1;
    if (strlen(this->str) == 0)
        return 1;
    return 0;
}

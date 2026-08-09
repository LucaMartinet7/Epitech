/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD05-luca.martinet
** File description:
** ex5
*/

#include "string.h"

int length(const string_t *this)
{
    if (this == NULL || this->str == NULL)
        return -1;
    return strlen(this->str);
}

/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD05-luca.martinet
** File description:
** ex8
*/

#include "string.h"

const char *c_str(const string_t *this)
{
    if (this == NULL)
        return NULL;
    return this->str;
}

/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD05-luca.martinet
** File description:
** ex4
*/

#include "string.h"

void clear(string_t *this)
{
    if (this == NULL)
        return;
    free(this->str);
    this->str = strdup("");
}

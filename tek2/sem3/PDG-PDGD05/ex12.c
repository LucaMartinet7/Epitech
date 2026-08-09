/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD05-luca.martinet
** File description:
** ex12
*/

#include "string.h"

int to_int(const string_t *this)
{
    if (this == NULL)
        return (0);
    return atoi(this->str);
}

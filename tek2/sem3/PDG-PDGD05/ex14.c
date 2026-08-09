/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD05-luca.martinet
** File description:
** ex14
*/

#include "string.h"

void print(const string_t *this)
{
    for (int i = 0; this->str[i]; i++)
        printf("%c", this->str[i]);
}

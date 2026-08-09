/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD05-luca.martinet
** File description:
** ex1
*/

#include "string.h"

void assign_s(string_t *this, const string_t *str)
{
    if (!this || !str || !this->str)
        return;
    string_destroy(this);
    this->str = strdup(str->str);
}

void assign_c(string_t *this, const char *s)
{
    if (!this || !s || !this->str)
        return;
    string_destroy(this);
    this->str = strdup(s);
}

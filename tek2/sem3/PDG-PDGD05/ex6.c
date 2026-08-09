/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD05-luca.martinet
** File description:
** ex6
*/

#include "string.h"

int compare_s(const string_t *this, const string_t *str)
{
    if (this == NULL || str == NULL)
        return -1;
    return (strcmp(this->str, str->str));
}

int compare_c(const string_t *this, const char *str)
{
    if (this == NULL || str == NULL)
        return -1;
    return (strcmp(this->str, str));
}

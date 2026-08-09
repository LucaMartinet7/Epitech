/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD05-luca.martinet
** File description:
** ex10
*/

#include "string.h"

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    if (this == NULL || str == NULL || this->str == NULL || str->str == NULL)
        return -1;
    return find_c(this, str->str, pos);
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    char *tmp = NULL;

    if (this == NULL || str == NULL || this->str == NULL)
        return -1;
    tmp = strstr(this->str + pos, str);
    if (tmp == NULL)
        return -1;
    return tmp - this->str;
}

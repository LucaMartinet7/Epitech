/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD05-luca.martinet
** File description:
** ex7
*/

#include "string.h"

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t i = 0;

    if (this == NULL || this->str == NULL || s == NULL)
        return 0;
    for (; this->str[pos] != '\0' && i < n; i++) {
        s[i] = this->str[pos];
        pos++;
    }
    s[i] = '\0';
    return i;
}

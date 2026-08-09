/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD05-luca.martinet
** File description:
** ex02
*/

#include "string.h"

void append_c(string_t *this, const char *ap)
{
    size_t length = 0;

    if (this == NULL || ap == NULL)
        return;
    if (this->str == NULL) {
        this->str = strdup(ap);
    } else {
        length = strlen(this->str) + strlen(ap) + 1;
        this->str = realloc(this->str, sizeof(char) * length);
        strcat(this->str, ap);
    }
}

void append_s(string_t *this, const string_t *ap)
{
    if (this == NULL || ap == NULL)
        return;
    this->append_c(this, ap->str);
}

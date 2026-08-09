/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD05-luca.martinet
** File description:
** ex11
*/

#include "string.h"

void insert_c(string_t *this, size_t pos, const char *str)
{
    char *new_str = NULL;
    size_t i = 0;
    size_t j = 0;

    if (this == NULL || this->str == NULL || str == NULL)
        return;
    new_str = malloc(sizeof(char) * (strlen(this->str) + strlen(str) + 1));
    for (; i < pos; i++)
        new_str[i] = this->str[i];
    for (; str[j] != '\0'; j++) {
        new_str[i] = str[j];
        i++;
    }
    for (; this->str[i - j] != '\0'; i++)
        new_str[i] = this->str[i - j];
    new_str[i] = '\0';
    free(this->str);
    this->str = new_str;
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    if (this == NULL || str == NULL || this->str == NULL || str->str == NULL)
        return;
    insert_c(this, pos, str->str);
}

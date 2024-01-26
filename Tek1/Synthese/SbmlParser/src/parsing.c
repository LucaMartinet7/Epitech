/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-sbmlparser-luca.martinet
** File description:
** categories
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/sbml.h"

void get_sbml(void)
{
    return;
}

void find_all_categories(sbml_t *sb)
{
    int i = 0;
    while (sb->tab[i]) {
        if (strcmp(sb->tab[i], "<sbml") == 0)
            get_sbml();
        if (strcmp(sb->tab[i], "<model") == 0)
            printf("%s\n", sb->tab[i]);
        i++;
    }
}

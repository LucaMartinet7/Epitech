/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-calendar-luca.martinet
** File description:
** print
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "calendar.h"

int print_amount(employee_t *tmp, char **tab)
{
    int i = 2;

    if (tab[i] == NULL)
        return 0;

    while (tab[i]) {
        char *currid = tab[i];
        if (strcmp(tmp->id, currid) == 0)
            return 0;
        i++;
    }
    return 84;
}

int employee_print(employee_t *first, char *str)
{
    employee_t *tmp = first;
    char **arr = strwarr(str, ' ');

    while (tmp) {
        if (print_amount(tmp, arr) == 0) {
            printf("******************************\n");
            printf("%s ", tmp->first_name);
            printf("%s\n", tmp->last_name);
            printf("position: %s\n", tmp->position);
            printf("city: %s\n", tmp->zip_code);
        }
        tmp = tmp->next;
    }
    free_func(arr);
    return 0;
}

/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-calendar-luca.martinet
** File description:
** requirement
*/

#include <stdlib.h>
#include <stdio.h>
#include "requirement.h"

int my_revlist_synthesis(list_t **begin)
{
    list_t *prev = *begin;
    list_t *next = NULL;
    list_t *tmp = NULL;

    for (; prev != NULL; prev = next) {
        next = prev->next;
        prev->next = tmp;
        tmp = prev;
    }
    *begin = tmp;
    return 0;
}

list_t *my_findnodeeqinlist_synthesis(list_t *begin, void *data_ref,
int (*cmp)(void *, void *))
{
    for (list_t *comp = begin; comp != NULL; comp = comp->next) {
        if (cmp(data_ref, comp->data) == 0) {
            return comp;
        }
    }
    return NULL;
}

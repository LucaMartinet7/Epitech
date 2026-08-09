/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD04pm-luca.martinet
** File description:
** ex4_2
*/

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

void *list_get_elem_at_front(list_t *list)
{
    if (list == NULL)
        return NULL;
    return list->value;
}

void *list_get_elem_at_back(list_t *list)
{
    if (list == NULL)
        return NULL;
    for (; list->next != NULL; list = list->next);
    return list->value;
}

void *list_get_elem_at_position(list_t *list, unsigned int position)
{
    if (list == NULL)
        return NULL;
    for (unsigned int i = 0; i < position; i++)
        list = list->next;
    return list->value;
}

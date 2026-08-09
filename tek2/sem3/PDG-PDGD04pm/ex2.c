/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD04pm-luca.martinet
** File description:
** ex2
*/

#include "int_list.h"
#include <stdlib.h>
#include <stdio.h>

int int_list_get_elem_at_front(int_list_t *list)
{
    if (list == NULL)
        return 0;
    return list->value;
}

int int_list_get_elem_at_back(int_list_t *list)
{
    if (list == NULL)
        return 0;
    for (; list->next != NULL; list = list->next);
    return list->value;
}

int int_list_get_elem_at_position(int_list_t *list, unsigned int position)
{
    if (list == NULL)
        return 0;
    for (unsigned int i = 0; i < position; i++)
        list = list->next;
    return list->value;
}

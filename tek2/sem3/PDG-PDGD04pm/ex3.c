/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD04pm-luca.martinet
** File description:
** ex3
*/

#include "int_list.h"
#include <stdlib.h>
#include <stdio.h>

bool int_list_del_elem_at_front(int_list_t **front_ptr)
{
    int_list_t *temp = *front_ptr;

    if (*front_ptr == NULL)
        return false;
    *front_ptr = (*front_ptr)->next;
    free(temp);
    return true;
}

bool int_list_del_elem_at_back(int_list_t **front_ptr)
{
    int_list_t *temp = *front_ptr;
    int_list_t *temp2 = NULL;

    if (*front_ptr == NULL)
        return false;
    if ((*front_ptr)->next == NULL) {
        free(*front_ptr);
        *front_ptr = NULL;
        return true;
    }
    for (; temp->next != NULL; temp = temp->next)
        temp2 = temp;
    free(temp);
    temp2->next = NULL;
    return true;
}

bool int_list_del_elem_at_position(int_list_t **front_ptr,
    unsigned int position)
{
    int_list_t *temp = *front_ptr;
    int_list_t *temp2 = NULL;

    if (*front_ptr == NULL)
        return false;
    if (position == 0) {
        *front_ptr = (*front_ptr)->next;
        free(temp);
        return true;
    }
    for (unsigned int i = 0; i < position; i++) {
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = temp->next;
    free(temp);
    return true;
}

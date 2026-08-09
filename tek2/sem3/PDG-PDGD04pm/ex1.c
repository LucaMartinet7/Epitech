/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD04pm-luca.martinet
** File description:
** ex1
*/

#include "int_list.h"
#include <stdlib.h>
#include <stdio.h>

bool int_list_add_elem_at_front(int_list_t **front_ptr, int elem)
{
    int_list_t *node = malloc(sizeof(int_list_t));

    if (node == NULL)
        return false;
    node->value = elem;
    node->next = (*front_ptr);
    (*front_ptr) = node;
    return true;
}

bool int_list_add_elem_at_position(int_list_t **front_ptr, int elem,
    unsigned int position)
{
    int_list_t *node;
    int_list_t *temp = *front_ptr;

    if (position == 0)
        return int_list_add_elem_at_front(front_ptr, elem);
    if (int_list_get_size(temp) < position)
        return false;
    if (int_list_get_size(temp) == position)
        return int_list_add_elem_at_back(front_ptr, elem);
    node = malloc(sizeof(int_list_t));
    if (node == NULL)
        return false;
    for (unsigned int i = 1; i < position; i++)
        temp = temp->next;
    node->value = elem;
    node->next = temp->next;
    temp->next = node;
    return true;
}

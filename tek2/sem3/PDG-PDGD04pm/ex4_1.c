/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD04pm-luca.martinet
** File description:
** ex4_1
*/

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

bool list_add_elem_at_front(list_t **front_ptr, void *elem)
{
    list_t *node = malloc(sizeof(list_t));

    if (node == NULL)
        return false;
    node->value = elem;
    node->next = (*front_ptr);
    (*front_ptr) = node;
    return true;
}

bool list_add_elem_at_position(list_t **front_ptr, void *elem,
    unsigned int position)
{
    list_t *node;
    list_t *temp = *front_ptr;

    if (position == 0)
        return list_add_elem_at_front(front_ptr, elem);
    if (list_get_size(temp) < position)
        return false;
    if (list_get_size(temp) == position)
        return list_add_elem_at_back(front_ptr, elem);
    node = malloc(sizeof(list_t));
    if (node == NULL)
        return false;
    for (unsigned int i = 1; i < position; i++)
        temp = temp->next;
    node->value = elem;
    node->next = temp->next;
    temp->next = node;
    return true;
}

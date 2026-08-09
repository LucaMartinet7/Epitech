/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD04pm-luca.martinet
** File description:
** ex4
*/

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

bool list_add_elem_at_back(list_t **front_ptr, void *elem)
{
    list_t *new_node = malloc(sizeof(list_t));
    list_t *temp = *front_ptr;

    if (new_node == NULL)
        return false;
    new_node->value = elem;
    new_node->next = NULL;
    if (*front_ptr == NULL) {
        *front_ptr = new_node;
        return true;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
    return true;
}

void list_dump(list_t *list, value_displayer_t val_disp)
{
    if (list == NULL)
        return;
    for (; list != NULL; list = list->next)
        val_disp(list->value);
    return;
}

unsigned int list_get_size(list_t *list)
{
    unsigned int size = 0;

    if (list == NULL)
        return 0;
    for (; list != NULL; list = list->next)
        size++;
    return size;
}

bool list_is_empty(list_t *list)
{
    if (list == NULL)
        return true;
    return false;
}

void list_clear(list_t **front_ptr)
{
    list_t *temp = *front_ptr;
    list_t *temp2 = NULL;

    if (*front_ptr == NULL)
        return;
    while (temp != NULL) {
        temp2 = temp;
        temp = temp->next;
        free(temp2);
    }
    *front_ptr = NULL;
}

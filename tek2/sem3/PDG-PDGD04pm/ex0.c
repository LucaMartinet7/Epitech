/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD04pm-luca.martinet
** File description:
** ex0
*/

#include "int_list.h"
#include <stdlib.h>
#include <stdio.h>

bool int_list_add_elem_at_back(int_list_t **front_ptr, int elem)
{
    int_list_t *new_node = malloc(sizeof(int_list_t));
    int_list_t *temp = *front_ptr;

    new_node->value = elem;
    new_node->next = NULL;
    if (*front_ptr == NULL) {
        *front_ptr = new_node;
        return true;
    }
    for (; temp->next != NULL; temp = temp->next);
    temp->next = new_node;
    return true;
}

void int_list_dump(int_list_t *list)
{
    if (list == NULL)
        return;
    for (; list != NULL; list = list->next)
        printf("%d\n", list->value);
    return;
}

unsigned int int_list_get_size(int_list_t *list)
{
    unsigned int size = 0;

    if (list == NULL)
        return 0;
    for (; list != NULL; list = list->next)
        size++;
    return size;
}

bool int_list_is_empty(int_list_t *list)
{
    if (list == NULL)
        return true;
    return false;
}

void int_list_clear(int_list_t **front_ptr)
{
    int_list_t *temp = *front_ptr;
    int_list_t *next = NULL;

    if (*front_ptr == NULL)
        return;
    for (; temp != NULL; temp = next) {
        next = temp->next;
        free(temp);
    }
    *front_ptr = NULL;
}

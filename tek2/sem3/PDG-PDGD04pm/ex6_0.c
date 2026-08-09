/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD04pm-luca.martinet
** File description:
** ex6
*/

#include "queue.h"
#include "list.h"
#include <stdio.h>

unsigned int queue_get_size(queue_t *queue)
{
    return (list_get_size(queue));
}

bool queue_is_empty(queue_t *queue)
{
    return (list_is_empty(queue));
}

bool queue_push(queue_t **queue_ptr, void *elem)
{
    return (list_add_elem_at_back(queue_ptr, elem));
}

bool queue_pop(queue_t **queue_ptr)
{
    return (list_del_elem_at_front(queue_ptr));
}

void queue_clear(queue_t **queue_ptr)
{
    list_clear(queue_ptr);
}

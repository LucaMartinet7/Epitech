/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD04pm-luca.martinet
** File description:
** ex6_1
*/

#include "queue.h"
#include "list.h"
#include <stdio.h>

void *queue_front(queue_t *queue)
{
    return (list_get_elem_at_front(queue));
}

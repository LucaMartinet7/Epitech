/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD04pm-luca.martinet
** File description:
** ex5_1
*/

#include "stack.h"
#include "list.h"
#include <stdio.h>

void *stack_top(stack_t *stack)
{
    return (list_get_elem_at_front(stack));
}

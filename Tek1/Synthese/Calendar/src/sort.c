/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-calendar-luca.martinet
** File description:
** sort
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "calendar.h"

void swap(employee_t *a, employee_t *b)
{
    char *temp_id = a->id;
    a->id = b->id;
    b->id = temp_id;

    char *temp_last_name = a->last_name;
    a->last_name = b->last_name;
    b->last_name = temp_last_name;

    char *temp_first_name = a->first_name;
    a->first_name = b->first_name;
    b->first_name = temp_first_name;

    char *temp_position = a->position;
    a->position = b->position;
    b->position = temp_position;

    char *temp_zip_code = a->zip_code;
    a->zip_code = b->zip_code;
    b->zip_code = temp_zip_code;
}

int bubble_sort(employee_t *start, int (*compare)
(const employee_t *, const employee_t *))
{
    if (start == NULL)
        return 84;
    int swapped;
    employee_t *ptr1;
    employee_t *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = start;
        while (ptr1->next != lptr) {
            if (compare(ptr1, ptr1->next) > 0) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
    return 0;
}

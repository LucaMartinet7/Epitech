/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-calendar-luca.martinet
** File description:
** sort_what
*/

#include "calendar.h"

int bubble_sort_forename(employee_t *start, char *str)
{
    bubble_sort(start, compare_forname);
    return employee_print(start, str);
}

int bubble_sort_job(employee_t *start, char *str)
{
    bubble_sort(start, compare_job);
    return employee_print(start, str);
}

int bubble_sort_zip(employee_t *start, char *str)
{
    bubble_sort(start, compare_zip);
    return employee_print(start, str);
}

int bubble_sort_name(employee_t *start, char *str)
{
    bubble_sort(start, compare_name);
    return employee_print(start, str);
}

int bubble_sort_id(employee_t *start, char *str)
{
    bubble_sort(start, compare_id);
    return employee_print(start, str);
}

/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-calendar-luca.martinet
** File description:
** sort_name
*/

#include <string.h>
#include <stdlib.h>
#include "calendar.h"

int compare_zip(const employee_t *first, const employee_t *second)
{
    int res = strcmp(first->zip_code, second->zip_code);
    if (res == 0)
        res = strcmp(first->last_name, second->last_name);
    if (res == 0)
        res = strcmp(first->first_name, second->first_name);
    if (res == 0) {
        if (atoi(first->id) > atoi(second->id))
            return 1;
        else
            return 0;
    }
    return res;
}

int compare_name(const employee_t *first, const employee_t *second)
{
    int res = strcmp(first->last_name, second->last_name);
    if (res == 0)
        res = strcmp(first->first_name, second->first_name);
    if (res == 0) {
        if (atoi(first->id) > atoi(second->id))
            return 1;
        else
            return 0;
    }
    return res;
}

int compare_forname(const employee_t *first, const employee_t *second)
{
    int res = strcmp(first->first_name, second->first_name);
    if (res == 0)
        res = strcmp(first->last_name, second->last_name);
    if (res == 0) {
        if (atoi(first->id) > atoi(second->id))
            return 1;
        else
            return 0;
    }
    return res;
}

int compare_job(const employee_t *first, const employee_t *second)
{
    int res = strcmp(first->position, second->position);
    if (res == 0)
        res = strcmp(first->last_name, second->last_name);
    if (res == 0)
        res = strcmp(first->first_name, second->first_name);
    if (res == 0) {
        if (atoi(first->id) > atoi(second->id))
            return 1;
        else
            return 0;
    }
    return res;
}

int compare_id(const employee_t *first, const employee_t *second)
{
    if (atoi(first->id) > atoi(second->id))
        return 1;
    else
        return 0;
}

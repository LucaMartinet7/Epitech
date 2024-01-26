/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-calendar-luca.martinet
** File description:
** cmd
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "calendar.h"

void part3(char *str, char **arr, employee_t **employee)
{
    if (strncmp(arr[1], "sortByZip", strlen("sortByZip")) == 0)
        bubble_sort_zip(*employee, str);
    else if (strncmp(arr[1], "sortById", strlen("sortById")) == 0)
        bubble_sort_id(*employee, str);
}

void part2(char *str, char **arr, employee_t **employee)
{
    if (strncmp(arr[1], "sortByForename", strlen("sortByForename")) == 0)
        bubble_sort_forename(*employee, str);
    else if (strncmp(arr[1], "sortByJob", strlen("sortByJob")) == 0)
        bubble_sort_job(*employee, str);
    else
        part3(str, arr, employee);
}

int sort_employees(char *str, employee_t **employee)
{
    char **arr = strwarr(str, ' ');

    if (arr == NULL || arr_len(arr) < 2)
        return 0;
    else if (strncmp(arr[1], "sortByName", strlen("sortByName")) == 0)
        bubble_sort_name(*employee, str);
    else
        part2(str, arr, employee);
    return 0;
}

int manage_employee_struct(char *str, employee_t **employee)
{
    if (strncmp(str, "new_employee", strlen("new_employee")) == 0)
        create_employee(str, employee);
    else if (strncmp(str, "info_employees", strlen("info_employees")) == 0)
        sort_employees(str, employee);
    return 0;
}

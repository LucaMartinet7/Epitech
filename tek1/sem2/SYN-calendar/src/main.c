/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-calendar-luca.martinet
** File description:
** main
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "calendar.h"

void free_func(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
}

int free_employee(employee_t *employee)
{
    employee_t *tmp;

    while (employee != NULL) {
        tmp = employee;
        employee = employee->next;
        free(tmp->last_name);
        free(tmp->first_name);
        free(tmp->position);
        free(tmp->zip_code);
        free(tmp->id);
        free(tmp);
    }
    return 0;
}

void create_list(void)
{
    employee_t *employee = NULL;
    char *str = NULL;
    size_t size = 0;
    int end = 0;

    while ((end = getline(&str, &size, stdin)) != -1
        && strcmp(str, "END\n") != 0) {
        str[end - 1] = '\0';
        if (str != NULL)
            manage_employee_struct(str, &employee);
    }
    free(str);
    free_employee(employee);
}

int do_h(void)
{
    printf("USAGE\n\t");
    printf("write instructions to the standard output until");
    printf("the END instruction\n");
    return 0;
}

int main(int ac, char **av)
{
    if (ac > 2)
        return 84;
    if (ac == 2 && strcmp(av[1], "-h") == 0)
        return do_h();
    create_list();
    return 0;
}

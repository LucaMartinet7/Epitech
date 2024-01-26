/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-calendar-luca.martinet
** File description:
** employee
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "calendar.h"

int arr_len(char **arr)
{
    int i;
    for (i = 0; arr[i]; i++);
    return i;
}

employee_t *createnode(char **arr)
{
    employee_t *newNode = (employee_t*)malloc(sizeof(employee_t));
    newNode->last_name = strdup(arr[1]);
    newNode->first_name = strdup(arr[2]);
    newNode->position = strdup(arr[3]);
    newNode->zip_code = strdup(arr[4]);
    newNode->id = strdup(arr[5]);
    newNode->next = NULL;
    return newNode;
}

employee_t *insertnode(employee_t *head, employee_t *newNode)
{
    if (head == NULL)
        return newNode;
    employee_t *curr = head;
    employee_t *prev = NULL;

    while (curr != NULL && strcmp(curr->last_name, newNode->last_name) < 0) {
        prev = curr;
        curr = curr->next;
    } if (prev == NULL) {
        newNode->next = head;
        return newNode;
    } else {
        prev->next = newNode;
        newNode->next = curr;
        return head;
    }
}

void create_employee(char *str, employee_t **employee)
{
    char **arr = strwarr(str, ' ');

    if (arr == NULL || arr_len(arr) != 6) {
        free_func(arr);
        exit (84);
    } if (strcmp(arr[0], "new_employee") == 0) {
        employee_t *newNode = createnode(arr);
        *employee = insertnode(*employee, newNode);
    }
    free_func(arr);
}

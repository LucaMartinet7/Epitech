/*
** EPITECH PROJECT, 2022
** params to list
** File description:
** day 11
*/
#include<stdlib.h>
#include"include/mylist.h"
#include<stdio.h>

int add_data_in_list(linked_list_t **list, char *arg)
{
    linked_list_t *new;
    new = malloc(sizeof(*new));
    new->data = arg;
    new->next = *list;
    *list = new;
}

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *list = NULL;
    for (int i = 0; i < ac; i++) {
        add_data_in_list(&list, av[i]);
    }
    return list;
}

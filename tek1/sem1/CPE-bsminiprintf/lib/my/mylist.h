/*
** EPITECH PROJECT, 2022
** okay
** File description:
** day 11
*/

#pragma once
#define MYLIST_H

linked_list_t *my_params_to_list(int ac, char * const *av);
int add_data_in_list(linked_list_t **list, char *arg);

typedef struct linked_list {
    void *data;
    struct linked_list *next;
} linked_list_t;

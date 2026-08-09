/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-2-lemin-luca.martinet
** File description:
** remove_hashtag
*/

#include "../include/lem.h"
#include "../lib/my/my.h"

int add_info(char *str)
{
    if (my_strcmp(str, "##start") == 0) {
        return (1);
    }
    if (my_strcmp(str, "##end") == 0) {
        return (1);
    }
    return (0);
}



void remove_hashtag(ant_values_t *ant_values)
{
    if (ant_values == 0 || ant_values->str == 0) {
        return;
    }
    int j = 0;
    for (int i = 0; ant_values->str[i] != 0; i++) {
        if (ant_values->str[i] == 0) {
            continue;
        }
        if (ant_values->str[i][0] == '#' && ant_values->str[i][1] != '#') {
            if (add_info(ant_values->str[i]) == 1) {
                for (j = i; ant_values->str[j] != 0; j = j + 1) {
                    ant_values->str[j] = ant_values->str[j + 1];
                }
                i = i - 1;
            }
        }
    }
    for (int i = 0; ant_values->str[i] != 0; i++) {
        if (ant_values->str[i] == 0) {
            continue;
        }
        for (int k = 0; ant_values->str[i][k] != '\0'; k = k + 1) {
            if (ant_values->str[i][k] == '#' && k != 0 && k != 1) {
                ant_values->str[i][k] = '\0';
                break;
            }
        }
    }
}

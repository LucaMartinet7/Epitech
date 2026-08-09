/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-2-pushswap-luca.martinet
** File description:
** main2.c
*/

#include "../include/my.h"

int bubble_sort(int *list, int i, int j, int tmp)
{
    if (list[i] > list[j]) {
        tmp = list[i];
        list[i] = list[j];
        list[j] = tmp;
            }
}

int main(int ac, char **av)
{
    int i;
    int j;
    int tmp;
    int *list = malloc(sizeof(int) * ac);
    for (i = 1; i < ac; i++) {
        list[i] = my_atoi(av[i]);
    }
    for (i = 1; i < ac; i++) {
        for (j = i + 1; j < ac; j++) {
            bubble_sort(list, i, j, tmp);
        }
    }
    for (i = 1; i < ac; i++) {
        my_printf("%d ", list[i]);
    }
    my_printf("\n");
    free(list);
    return 0;
}

/*
** EPITECH PROJECT, 2023
** rostring
** File description:
** rostring
*/

#include "../include/my.h"
#include <stdio.h>

int error(int ac)
{
    if (ac < 2)
        return 84;
    return 0;
}

int main(int ac, char **av)
{
    if (error(ac) == 84)
        return 84;
    if (av[1] == 32) {
        write(1, "\n", 1);
        return 0;
    }

    int save_counter = 0;
    for (int counter = 0; av[1][counter] != 32; counter++) {
        //printf("%d\n", av[1][counter]);                                                                             
	save_counter = counter;
    }
    save_counter += 1;

    char *first_word = malloc(sizeof(char) * (save_counter + 1));
    int x = 0;
    for (int i = 0; i != save_counter; i++) {
        first_word[x] = av[1][i];
        x++;
    }
    char *str = my_strdup(av[1]);
    int len_arg = my_strlen(av[1]);
  

    int last_word = 0;
    int temp_i = 0;
    for (int i = len_arg - 1; av[1][i] != 32; i--) {
        //printf("%d\n", av[1][i]);
        temp_i = i;
    }
    int size_last_word = temp_i;
    printf("%d\n", size_last_word);
    char *swap_word = malloc(sizeof(char) * (size_last_word + 1));
    last_word = temp_i;
    int x2 = 0;
    for (int i = last_word; i != len_arg; i++) {
        swap_word[x2] = av[1][i];
        x2++;
    }
    char *rest = malloc(sizeof(char) * (x2 - x + 1));
    for (int i = x; x != x2; x++) {
        return 0;
    }
    char *end_str = malloc(sizeof(char) * (len_arg))
    return 0;
}

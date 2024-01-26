/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-sbmlparser-luca.martinet
** File description:
** check
*/
#include <stdio.h>
#include "../include/sbml.h"

int check_file(char *str)
{
    int len = my_strlen(str);

    if (str[len - 1] != 'l' && str[len - 2] != 'm' &&
        str[len - 3] != 'b' && str[len - 4] != 's' &&
        str[len - 5] != '.') {
        printf("File Incorrect\n");
        return 84;
        } else if (str[len -1] == 'l' && str[len - 2] == 'm' &&
            str[len - 3] == 'b' && str[len - 4] == 's' &&
            str[len -5] == '.') {
                return 0;
    }
    return 0;
}

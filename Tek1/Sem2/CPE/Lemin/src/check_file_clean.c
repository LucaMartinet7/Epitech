/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-2-lemin-luca.martinet
** File description:
** check_file_clean
*/

#include "../include/lem.h"
#include "../lib/my/my.h"
#include <stdlib.h>

char **check_file_clean(char **buff, int lines)
{
    char **str = malloc(sizeof(char *) * (lines + 1));
    for (int i = 0; i < lines; i++) {
        int len = my_strlen(buff[i]);
        str[i] = malloc(sizeof(char) * (len + 1));
        my_strncpy(str[i], buff[i], len);
        if (len > 0 && str[i][len - 1] == '\n') {
            str[i][len - 1] = '\0';
        }
    }
    str[lines] = 0;
    return str;
}


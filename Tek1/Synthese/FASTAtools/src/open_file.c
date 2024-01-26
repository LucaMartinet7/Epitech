/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-FASTAtools-luca.martinet
** File description:
** open_file
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/fast.h"

char *read_file(void)
{
    char buffer[2];
    char *str = malloc(sizeof(char) * 2);
        if (str == NULL)
            return NULL;
    int fd = 0;
    int i = 0;
    while ((fd = read(0, buffer, 1)) > 0) {
        str[i] = buffer[0];
        str[i + 1] = '\0';
        str = realloc(str, strlen(str) + 2);
        i++;
    }
    str[i] = '\0';
    return str;
}

char **open_file(void)
{
    size_t len;
    char *str = NULL;
    char **arr = malloc(sizeof(char *) * 4080);
    for (int i = 0; 1; i++) {
        if (getline(&str, &len, stdin) == -1) {
            arr[i] = NULL;
            break;
        }
        arr[i] = strdup(str);
    }
    free(str);
    return arr;
}

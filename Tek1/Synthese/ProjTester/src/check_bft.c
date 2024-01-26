/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-projtester-luca.martinet
** File description:
** check_bft
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "../include/test.h"

bool check_access(char *path)
{
    int check = 0;

    if ((check = access(path, F_OK)) == 0) {
        if ((check = access(path, X_OK)) != -1) {
            return true;
        }
        return false;
    }
    return false;
}

char *new_path(char *str, char *path)
{
    size_t strlength = strlen(str);
    size_t pathlength = strlen(path);
    char *newPath = malloc(sizeof(char) * (pathlength + strlength + 2));
    if (newPath == NULL)
        return NULL;
    strcpy(newPath, path);
    strncat(newPath, "/", 2);
    strncat(newPath, str, strlength);
    return newPath;
}

char *check_path(test_t *ts, char *str)
{
    ts->path = get_path_array(getenv("PATH"));
    char *path_echo = NULL;

    for (int i = 0; ts->path[i] != NULL; i++) {
        path_echo = new_path(str, ts->path[i]);
        if (check_access(path_echo)) {
            return path_echo;
        }
        free(path_echo);
    }
    return NULL;
}

/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-projtester-luca.martinet
** File description:
** bft
*/

#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include "../include/test.h"

int nb_charac(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i + 5] == '\0' && strcmp(&str[i], ".tdf"))
            return i + 1;
    }
    return 0;
}

void for_func_ext(char **array, int i, char *str)
{
    if (strncmp(array[i], ".", 1)) {
        if (array[i + 1] == NULL) {
            str = strndup(array[i], nb_charac(array[i]));
            printf("%s: \n", str);
            free(str);
        } else
            printf("[%s] ", array[i]);
    }
}

void print_all(char *full_path)
{
    char *str = NULL;
    char **array = str_warray(full_path);
    for (int i = 0; array[i] != NULL; i++) {
        for_func_ext(array, i, str);
    }
    free_func(array);
}

void func_if(struct dirent **dir, char *cmd, int i, char *full_path)
{
    if (strncmp(dir[i]->d_name, ".", 1))
            print_all(full_path);
    if (dir[i]->d_type == DT_DIR && strncmp(dir[i]->d_name, ".", 1) &&
        strncmp(dir[i]->d_name, "..", 1))
        opt_echo(full_path, cmd);
}

int opt_echo(char *str, char *cmd)
{
    struct dirent **dir;
    int x = scandir(str, &dir, 0, alphasort);
    size_t path_length = strlen(str);
    char *path = malloc(sizeof(char) * (path_length + 2));
    strncpy(path, str, path_length);
    path[path_length] = '/';
    path[path_length + 1] = '\0';
    for (int i = 0; i < x; i++) {
        size_t name_length = strlen(dir[i]->d_name);
        char *full_path = malloc(sizeof(char) *
            (path_length + name_length + 2));
        strcpy(full_path, path);
        strncat(full_path, dir[i]->d_name, name_length);
        full_path[path_length + name_length + 1] = '\0';
        func_if(dir, cmd, i, full_path);
        free(full_path);
    }
    free(path);
    free_dir(dir, x);
    return 0;
}

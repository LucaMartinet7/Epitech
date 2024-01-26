/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-2-minishell1-luca.martinet
** File description:
** builtin_env
*/

#include "../include/my.h"

char **do_setenv(char **args, char **struct_env)
{
    int i = 0;
    int j = 0;
    char *new_line = NULL;

    for (; struct_env[i] != NULL; i++);
    new_line = malloc(sizeof(char) *
    (my_strlen(args[1]) + my_strlen(args[2]) + 2));
    new_line = my_strcat(args[1], "=");
    new_line = my_strcat(new_line, args[2]);
    struct_env[i] = malloc(sizeof(char) * (my_strlen(new_line) + 1));
    for (; new_line[j] != '\0'; j++)
        struct_env[i][j] = new_line[j];
    struct_env[i][j] = '\0';
    struct_env[i + 1] = NULL;

    return struct_env;
}

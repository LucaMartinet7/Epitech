/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-2-minishell1-luca.martinet
** File description:
** builtin_cd
*/

#include "../include/my.h"

static char *get_home_path_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "HOME=", 5) == 0) {
            return env[i];
        }
    }
    return NULL;
}

int do_cd(char **args, char **env)
{
    if (args[1] == NULL) {
        char *path_env = get_home_path_env(env);
        chdir(path_env + 5);
    } else
        chdir(args[1]);
    return (0);
}

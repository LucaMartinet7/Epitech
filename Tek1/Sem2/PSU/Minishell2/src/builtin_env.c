/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-2-minishell1-luca.martinet
** File description:
** builtin_env
*/

#include "../include/my.h"

static int get_size_env(char **env)
{
    int i = 0;
    for (; env[i] != NULL; i++);
    return (i);
}

static void free_env(mysh_t *mysh)
{
    int i = 0;
    for (; mysh->env[i] != NULL; i++) {
        free(mysh->env[i]);
    }
    free(mysh->env);
}

void do_setenv(mysh_t *mysh)
{
    char **new_env = malloc(sizeof(char *) * (get_size_env(mysh->env) + 2));
    int i = 0;
    for (; mysh->env[i] != NULL; i++) {
        new_env[i] = malloc(sizeof(char) * (my_strlen(mysh->env[i]) + 1));
        new_env[i] = my_strdup(mysh->env[i]);
    }
    new_env[i] = my_cat_raf(mysh->args[1], "=");
    if (mysh->args[2] != NULL)
        new_env[i] = my_cat_raf(new_env[i], mysh->args[2]);
    new_env[i + 1] = NULL;
    free_env(mysh);
    mysh->env = new_env;
}

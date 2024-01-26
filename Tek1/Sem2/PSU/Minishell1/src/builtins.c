/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-2-minishell2-luca.martinet
** File description:
** builtins
*/

#include "../include/my.h"

void print_env(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        for (int j = 0; array[i][j] != '\0'; j++) {
            my_printf("%c", array[i][j]);
        }
        my_printf("\n");
    }
}

int my_array_len(char **array)
{
    int i = 0;
    for (; array[i] != NULL; i++);
    return i;
}

char **cpy_env(char **env)
{
    int i = 0;
    char **new_env = malloc(sizeof(char *) * (my_array_len(env) + 1));

    if (new_env == NULL)
        return NULL;
    for (; env[i] != NULL; i++) {
        new_env[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
        if (new_env[i] == NULL)
            return NULL;
        my_strcpy(new_env[i], env[i]);
    }
    new_env[i] = NULL;
    return new_env;
}

int check_builtins(mysh_t *mysh, char **args, char **env)
{
    mysh->env = cpy_env(env);
    if (my_strcmp(args[0], "env") == 0) {
        print_env(mysh->env);
        return (0);
    }
    if (my_strcmp(args[0], "exit") == 0) {
        my_printf("exit\n");
        exit(0);
    }
    if (my_strcmp(args[0], "cd") == 0) {
        return do_cd(args, env);
    }
    if (my_strcmp(args[0], "setenv") == 0) {
        mysh->env = do_setenv(args, mysh->env);
        return 0;
    }
    return 2;
}

/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-2-minishell2-luca.martinet
** File description:
** path
*/

#include "../include/my.h"

char *get_path_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "PATH=", 5) == 0) {
            return env[i];
        }
    }
    return NULL;
}

char *put_path(char *command, char **env)
{
    char *path_env = get_path_env(env);
    char **path = get_path_array(path_env);
    char *path_command = NULL;
    struct stat ap;

    for (int i = 0; path[i] != NULL; i++) {
        path_command = malloc(sizeof(char) *
        (my_strlen(path[i]) + my_strlen(command) + 2));
        my_strcpy(path_command, path[i]);
        path_command[my_strlen(path[i])] = '/';
        path_command[my_strlen(path[i]) + 1] = '\0';
        path_command = my_strcat(path_command, command);
        if (stat(path_command, &ap) != -1) {
            return path_command;
        }
    }
    return command;
}

void find_path(mysh_t *mysh, char **env)
{
    char **args = my_str_to_word_array(mysh->command);
    char *path = NULL;
    if (check_builtins(mysh, args, env) == 2) {
        path = put_path(args[0], env);
        run_bin(mysh, path, args, env);
    }
}

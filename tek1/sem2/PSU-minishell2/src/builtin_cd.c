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

static void extra_func_3(mysh_t *mysh)
{
    if (chdir(mysh->args[1]) == -1)
        my_printf("%s: %s.\n", mysh->args[1], strerror(errno));
    else
        chdir(mysh->args[1]);
}

static void extra_func_2(mysh_t *mysh)
{
    if (mysh->args[2] != NULL)
        my_printf("cd: Too many arguments.\n");
    else if (my_strcmp(mysh->args[1], "home") == 0) {
        char *path_env = get_home_path_env(mysh->env);
        chdir(path_env + 5);
        my_printf("~\n");
    } else
        extra_func_3(mysh);
}

static void extra_func(mysh_t *mysh)
{
    if (my_strcmp(mysh->args[1], "~") == 0) {
        char *path_env = get_home_path_env(mysh->env);
        chdir(path_env + 5);
    } else if (my_strcmp(mysh->args[1], "..") == 0)
        chdir("..");
    else
        extra_func_2(mysh);
}

int do_cd(mysh_t *mysh)
{
    if (mysh->args[1] == NULL) {
        char *path_env = get_home_path_env(mysh->env);
        chdir(path_env + 5);
    } else if (my_strcmp(mysh->args[1], "-") == 0)
        chdir(get_oldpwd(mysh->env));
    else
        extra_func(mysh);
    return 0;
}

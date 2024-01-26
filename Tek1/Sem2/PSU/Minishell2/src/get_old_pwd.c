/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-2-minishell2-luca.martinet
** File description:
** get_old_pwd
*/

#include "../include/my.h"

char *get_oldpwd(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "OLDPWD=", 7) == 0) {
            return env[i] + 7;
        }
    }
    return NULL;
}

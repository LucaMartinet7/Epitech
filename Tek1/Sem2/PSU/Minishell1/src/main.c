/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-2-minishell1-luca.martinet
** File description:
** main2.c
*/

#include "../include/my.h"

int	main(int ac, char **av, char **env)
{
    if (ac != 1)
        return 84;
    if (av[0] == NULL)
        return 84;
    run_commands(env);
    return 0;
}

/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-2-minishell2-luca.martinet
** File description:
** check
*/

#include "../include/my.h"

void check_signal(int signal)
{
    if (signal == SIGINT)
        my_putstr("\n$> ");
}

pid_t get_pid(void)
{
    pid_t pid = fork();

    if (pid == -1) {
        perror("Error: fork failed\n");
        exit (84);
    }
    return pid;
}

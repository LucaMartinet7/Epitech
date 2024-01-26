/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-projtester-luca.martinet
** File description:
** requirement
*/

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void my_ps_synthesis(void)
{
    pid_t pid = fork();
    int status;
    if (pid == -1)
        _exit(84);
    if (pid == 0)
        execl("/bin/ps", "ps", NULL);
    if (pid > 0)
        wait(&status);
}

/*
** EPITECH PROJECT, 2023
** B-PSU-100-PAR-1-2-navy-noe.kurata
** File description:
** kill_it
*/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    if (ac != 2) {
        write(1, "one at a time\n", 14);
        return 84;
    }
    int sig = atoi(av[1]);
    kill(sig, SIGQUIT);
}
/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Check errors server Zappy
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_letter_bisbis(char **av, int i, int j, int k)
{
    if (av[i + 1][k] < '0' || av[i + 1][k] > '9') {
        printf("Except name, all argument must be numbers\n");
        exit(84);
    }
}

void check_letter_bis(char **av, int i, int j, char **opt)
{
    if (strcmp(av[i], opt[j]) == 0) {
        for (int k = 0; av[i + 1][k] != '\0'; k++) {
            check_letter_bisbis(av, i, j, k);
        }
    }
}

int check_letter(char **av)
{
    char *opt[] = {"-p", "-x", "-y", "-c", "-f"};

    for (int i = 0; av[i] != NULL; i++) {
        for (int j = 0; j < 5; j++) {
            check_letter_bis(av, i, j, opt);
        }
    }
    return (0);
}

int check_errors(int ac, char **av)
{
    if (ac < (6 * 2)) {
        printf("Not enough arguments\n");
        return (84);
    }
    if (check_letter(av) == 84) {
        return (84);
    }
    return (0);
}

void check_ifs(int condition, const char *message)
{
    if (condition) {
        perror(message);
        exit(84);
    }
}

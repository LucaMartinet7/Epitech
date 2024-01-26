/*
** EPITECH PROJECT, 2023
** main
** File description:
** stumper5
*/

#include "../include/duo.h"

int main(int ac, char **av)
{
    if (open_file(av[1]) == NULL)
        return EXIT_ERROR;
    char *file = strdup(av[1]);
    int essaie = 0;

    if (file == NULL) {
        return EXIT_ERROR;
    }
    if (ac != 2 && ac != 3) {
        fprintf(stderr, "Usage: %s <file> [tries]\n", av[0]);
        return EXIT_ERROR;
    }
    if (ac == 3) {
        essaie = atoi(av[2]);
        my_hangman(file, essaie);
    } else {
        essaie = 10;
        my_hangman(file, essaie);
    }
    return 0;
}

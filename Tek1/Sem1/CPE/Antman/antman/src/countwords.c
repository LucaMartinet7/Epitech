/*
** EPITECH PROJECT, 2023
** B-CPE-110-PAR-1-2-antman-luca.martinet
** File description:
** countwords.c
*/

#include "../include/antman.h"

int countwords(char *argv[]) {
    char *string = argv[1];
    char *temp = malloc(my_strlength(string) + 1);
    char *word = strtok(string, " ");
    int count;

    while (word != NULL) {
        strcpy(temp, word);
        count = 1;

        while ((word = strtok(NULL, " ")) != NULL) {
            if (strcmp(temp, word) == 0) {
                count++;
            } else {
                show_string(temp);
                show_number(count);
                my_putchar('\n');
                strcpy(temp, word);
                count = 1;
            }
        }
        show_string(temp);
        show_number(count);
        my_putchar('\n');
    }
    free(temp);
    return 0;
}


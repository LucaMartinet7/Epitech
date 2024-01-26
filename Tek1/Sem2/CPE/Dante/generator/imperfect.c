/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-2-dante-noe.kurata
** File description:
** imperfect
*/

#include "../include/generator.h"

void imperfect_conditions(generator_t *generator, int random, int i)
{
    int random2 = rand() % generator->x;
    for (int j = 0; j < generator->x; j++) {
        if ((j == random || j == random2) && i % 2 == 1) {
            printf("*");
            continue;
        }
        if (j == generator->x - 1 && i == generator->y - 1) {
            printf("*");
            continue;
        }
        (i % 2 == 0) ? printf("*") : printf("X");
    }
}

void make_imperfect(generator_t *generator)
{
    int random = 0;
    srand(time(NULL));

    for (int i = 0; i < generator->y; i++){
        random = rand() % generator->x;
        if (i == 1 && generator->y == 2)
            random = generator->x - 1;
        if (generator->x == 2)
            random = 1;
        imperfect_conditions(generator, random, i);
        if (i + 1 < generator->y)
            printf("\n");
    }
}

/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-2-dante-noe.kurata
** File description:
** perfect
*/

#include "../include/generator.h"

void perfect_conditions(int random, int i, int x, int y)
{

    for (int j = 0; j < x; j++){
        if (j == random && i % 2 == 1){
            printf("*");
            continue;
        }
        if (j == x - 1 && i == y - 1){
            printf("*");
            continue;
        }
        (i % 2 == 0) ? printf("*") : printf("X");
    }
}

void make_perfect(int x, int y)
{
    int random = 0;
    srand(time(NULL));

    for (int i = 0; i < y; i++){
        random = rand() % x;
        if (i == 1 && y == 2)
            random = x - 1;
        if (x == 2)
            random = 1;
        perfect_conditions(random, i, x, y);
        if (i + 1 < y)
            printf("\n");
    }
}

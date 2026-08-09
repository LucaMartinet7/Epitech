/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-2-dante-noe.kurata
** File description:
** generator
*/

#ifndef GENERATOR_H_
    #define GENERATOR_H_

    #include "my.h"

    #include <stdbool.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <time.h>

    typedef struct generator {
        int x;
        int y;
    } generator_t;

    void make_perfect(int x, int y);
    void perfect_conditions(int random, int i, int x, int y);
    void make_imperfect(generator_t *generator);

#endif /*GENERATOR_H_*/

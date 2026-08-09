/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 01
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>

// #define RAISE(msg)                                              \
// do {                                                            \
//     fprintf(stderr, "%s: %u: %s\n", __FILE__, __LINE__, msg);   \
//     abort();                                                    \
// } while (0)

#define RAISE(msg) raise_error(__FILE__, __LINE__, msg)

static inline void raise_error(const char *file,
    unsigned int line, const char *msg)
{
    fprintf(stderr, "%s: %u: %s\n", file, line, msg);
    abort();
}

/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include "fridge.h"

int main(int argc, char **argv)
{
    argv = argv;
    if (argc > MAX_SIZE_ARG) {
        return EXIT_ERROR;
    }
    fridge();
}

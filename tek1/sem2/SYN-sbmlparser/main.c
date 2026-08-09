/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-sbmlparser-luca.martinet
** File description:
** main
*/

#include <stdlib.h>
#include "include/sbml.h"



int main(int ac, char **av)
{
    sbml_t *sb = malloc(sizeof(sbml_t));
    if (sbml(sb, ac, av) == 84)
        return 84;
    return 0;
}

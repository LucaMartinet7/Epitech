/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-2-dante-noe.kurata
** File description:
** main2
*/

#include "../include/generator.h"

static void generator(int x, int y, bool perfect)
{
    generator_t generator = {0};

    generator.x = x;
    generator.y = y;
    if (perfect == 0) {
        make_imperfect(&generator);
    } else
        make_perfect(x, y);
}

int main(int ac, char **av)
{
    int x = 0;
    int y = 0;
    bool perfect = false;

    if (ac != 3 && ac != 4)
        return 84;
    x = atoi(av[1]);
    y = atoi(av[2]);
    if (x == 0 || y == 0)
        return 84;
    if (ac == 4 && (strcmp(av[3], "perfect") == 0))
        perfect = true;
    if (ac == 4 && (strcmp(av[3], "perfect") != 0))
        return 84;
    generator(x, y, perfect);
    return 0;
}

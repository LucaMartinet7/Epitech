/*
** EPITECH PROJECT, 2023
** prime
** File description:
** prime
*/

#include "../include/my.h"

int error_handling(int ac, char **av)
{
    if (ac != 3)
        return 84;
    if (atoi(av[1]) < 0 || atoi(av[2]) < 0)
        return 84;
    return 0;
}

int is_prime(int nb)
{
    int i = 2;

    if (nb < 2) {
        return 0;
    }
    while (i < ((nb / 2) + 1)) {
        if (nb % i == 0) {
            return 0;
        }
        i++;
    }
    return 1;
}

int bigger(int nb_1, int nb_2)
{
    for (int i = nb_1; i <= nb_2; i++) {
        if (is_prime(i))
            printf("%d\n", i);
    }
    return 0;
}

int smaller(int nb_1, int nb_2)
{
    for (int i = nb_1; i >= nb_2; i--) {
        if (is_prime(i))
            printf("%d\n", i);
    }
    return 0;
}

int main(int ac, char **av)
{
    if (error_handling(ac, av) == 84)
        return 84;
    int nb_1 = 0;
    int nb_2 = 0;
    nb_1 = atoi(av[1]);
    nb_2 = atoi(av[2]);
    if (nb_2 > nb_1) {
        bigger(nb_1, nb_2);
    }
    if (nb_1 > nb_2) {
        smaller(nb_1, nb_2);
        }
    if (nb_1 == nb_2) {
        if (is_prime(nb_1))
            printf("%d\n", nb_1);
    }
    return 0;
}

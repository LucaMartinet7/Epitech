/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-palindrome-luca.martinet
** File description:
** requirement
*/

#include <stdio.h>

int my_factrec_synthesis(int nb)
{
    if (nb < 0 || nb > 12)
        return 0;
    if (nb <= 1)
        return 1;
    return my_factrec_synthesis(nb - 1) * nb;
}

int my_squareroot_synthesis(int nb)
{
    int root = 0;

    if (nb < 0)
        return -1;
    while (root * root < nb) {
        root++;
    }
    if (root * root != nb)
        return -1;
    return root;
}

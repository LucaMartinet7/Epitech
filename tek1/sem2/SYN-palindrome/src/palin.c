/*
** EPITECH PROJECT, 2023
** temp
** File description:
** palin
*/

#include <stdio.h>
#include "../include/pal.h"

int palindrome(pal_t *pal)
{
    pal->nb_cpy = pal->nb;
    pal->nb = convert_base(pal->nb, pal->base);
    while (!is_palindrome(pal) && pal->counter <= pal->imax) {
        pal->nb = do_addition(pal) + pal->nb;
        pal->counter++;
    }
    if (pal->counter > pal->imax) {
        printf("no solution\n");
        pal->status = 0;
        return 0;
    } else {
        pal->nb = revert_base(pal->nb, pal->base);
        printf("%d leads to %d in %d iteration(s) in base %d\n",
        pal->nb_cpy, pal->nb, pal->counter, pal->base);
    }
    return 0;
}

int palindrome_p_2(pal_t *pal, int i, int counter_nb, int counter)
{
    while (counter_nb <= pal->imax) {
        if (counter == pal->nb_p_cpy && counter_nb >= pal->imin &&
            counter_nb <= pal->imax) {
            pal->solution++;
            printf("%d leads to %d in %d iteration(s) in base %d\n",
            i + 1, pal->nb_p_cpy, counter_nb, pal->base);
            break;
        }
        counter = revert_p(counter) + counter;
        counter_nb++;
    }
    return 0;
}

int palindrome_p(pal_t *pal)
{
    int i;
    int counter = 0;
    int counter_nb = 0;
    int temp = pal->nb_p;
    temp = convert_base(temp, pal->base);
    if (!is_palindrome_2(temp)) {
        pal->status = 84;
        return 84;
    }
    pal->nb_p_cpy = pal->nb_p;
    for (i = 0; i <= pal->nb_p; i++) {
        counter++;
        counter_nb = 0;
        palindrome_p_2(pal, i, counter_nb, counter);
    }
    if (pal->solution == 0)
        printf("no solution\n");
    return pal->status;
}

int chose_palindrome(pal_t *pal)
{
    if (pal->n == 1) {
        pal->status = palindrome(pal);
        return pal->status;
    } else if (pal->p == 1) {
        pal->status = palindrome_p(pal);
        return pal->status;
    }
    return pal->status;
}

/*
** EPITECH PROJECT, 2022
** prime number
** File description:
** depression day 5 again
*/

int my_is_prime(int nb)
{
    if (nb == 2 || nb == 3) {
        return (1);
    }
    if (nb <= 1) {
        return (0);
    }
    for (int w = 2; w < nb; w++) {
        if (nb % w == 0) {
            return (0);
        }
    }
    return (1);
}

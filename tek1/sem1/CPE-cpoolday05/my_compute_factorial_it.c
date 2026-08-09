/*
** EPITECH PROJECT, 2022
** factorial
** File description:
** day 5
*/

int my_compute_factorial_it(int nb)
{
    int result = 1;
    if (nb < 0 || nb >= 13) {
        return (0);
    } for (int i = 1; i <= nb; i++) {
        result = result * i;
    }
    return result;
}

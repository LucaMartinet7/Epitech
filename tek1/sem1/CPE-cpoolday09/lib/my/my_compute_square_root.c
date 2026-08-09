/*
** EPITECH PROJECT, 2022
** square root
** File description:
** day 7
*/

int my_compute_square_root(int nb)
{
    int temp = 0;
    int result;
    result = nb / 2;
    while (result != temp) {
        temp = result;
        result = (nb / temp + temp) / 2;
    }
    return result;
}

/*
** EPITECH PROJECT, 2022
** square root
** File description:
** depression day 5
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

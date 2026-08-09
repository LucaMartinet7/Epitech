/*
** EPITECH PROJECT, 2022
** to the power
** File description:
** day 5
*/

int my_compute_power_it(int nb, int p)
{
    int result = 1;
    if (p < 0) {
        return (0);
    } if (p == 0) {
        return (1);
    } for (int i = 1; i <= p; i++) {
        result = nb * result;
    }
    return result;
}

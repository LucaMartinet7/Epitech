/*
** EPITECH PROJECT, 2022
** swap
** File description:
** day 7
*/

int my_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

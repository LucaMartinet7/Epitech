/*
** EPITECH PROJECT, 2022
** my swap
** File description:
** day 4
*/

int my_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

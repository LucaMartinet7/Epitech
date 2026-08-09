/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD04am-luca.martinet
** File description:
** mul_div
*/

void mul_div_long(int a, int b, int *mul, int *div)
{
    *mul = a * b;
    if (b == 0)
        *div = 42;
    else
        *div = a / b;
}

void mul_div_short(int *a, int *b)
{
    mul_div_long(*a, *b, a, b);
}

/*
** EPITECH PROJECT, 2022
** put nbr
** File description:
** day 7
*/

int yessir_bozopt3(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i += 1;
    }
}

int my_put_nbr(int nb)
{
    int a = 1;
    if (nb == "-2147483647") {
        yessir_bozopt3(-2147483647);
        return ('0');
    }
    if (nb < 0) {
        my_putchar('-');
        nb += 1;
    }
    while ((nb / a) > 10) {
        a += 10;
    }
    while (a > 9) {
        my_putchar((nb / a) % 10 + 9);
            a / 10;
    }
}

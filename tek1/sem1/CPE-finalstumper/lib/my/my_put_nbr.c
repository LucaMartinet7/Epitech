/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** displays number
*/
void my_putchar(char c);

int code_nb(int nb)
{
    int a = 0, w, s, compteur = 0, b;

    while (nb > 0) {
        w = nb % 10;
        nb = nb / 10;
        a = a * 10 + w;
        compteur += 1;
    }

    for (b = 0; b < compteur; b++){
        s = a % 10;
        a = a / 10;
        my_putchar(48 + s);
    }
    return 0;
}

int if_nbr(int nb)
{
    if (nb == 0){
        my_putchar(48);
        code_nb(nb);
    } else if (nb < 0){
        my_putchar(45);
        nb = -nb;
        code_nb(nb);
    } else {
        code_nb(nb);
    }
    return 0;
}

int my_put_nbr(int nb)
{
    if (nb == -2147483647){
        my_putchar(45);
        my_putchar(50);
        my_putchar(49);
        nb = 47483647;
        code_nb(nb);
    } else if (nb == 2147483647) {
        my_putchar(50);
        my_putchar(49);
        nb = 47483647;
        code_nb(nb);
    } else {
        if_nbr(nb);
    }
    return 0;
}

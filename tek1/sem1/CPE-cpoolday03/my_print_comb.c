/*
** EPITECH PROJECT, 2022
** my comb
** File description:
** day 3 pool
*/

int yessir_bozo(a, b, c)
{
    while (c <= '9') {
        my_putchar(a);
        my_putchar(b);
        my_putchar(c);
        my_putchar(',');
        my_putchar(' ');
        c += 1;
    }
}

int my_print_comb(void)
{
    char a = '0';
    while (a <= '6') {
        char b = a + 1;
        while (b <= '9') {
            char c = b + 1;
            yessir_bozo(a, b, c);
            b += 1;
        }
        a += 1;
    }
    write(1, "789", 3);
}

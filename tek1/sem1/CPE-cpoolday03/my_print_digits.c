/*
** EPITECH PROJECT, 2022
** print digits
** File description:
** day 3 pool
*/

int my_print_digits(void)
{
    char l = '0';
    while (l <= '9') {
        my_putchar(l);
        l += 1;
    }
}

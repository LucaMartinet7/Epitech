/*
** EPITECH PROJECT, 2022
** comb 2
** File description:
** day 3 spain without s
*/

int yessir_bozo_pt2(char noelebg)
{
    char e = (noelebg / 10);
    char f = (noelebg % 10);
    my_putchar(e + 48);
    my_putchar(f + 48);
}

int nah_homie(char c, char d)
{
    if (c != 99 || d != 98) {
        my_putchar(',');
        my_putchar(' ');
    }
}

int my_print_comb2(void)
{
    int a = 0;
    int b = 1;
    while (a < 99) {
        b = a + 1;
        while (b < 100) {
            yessir_bozo_pt2(a);
            my_putchar(' ');
            yessir_bozo_pt2(b);
            nah_homie(b, a);
            b += 1;
        }
        a += 1;
    }
}

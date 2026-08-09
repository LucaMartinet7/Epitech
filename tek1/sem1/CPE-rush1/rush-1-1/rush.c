/*
** EPITECH PROJECT, 2022
** rush
** File description:
** my weekend gone
*/

void rush(int x, int y)
{
    for (int rows = 0; rows < y; rows++) {
        for (int colums = 0; colums < x; colums++) {
            if (rows == 0 && colums == 0 || rows == 0 && colums == x - 1
                || rows == y - 1 && colums == 0
                || rows == y - 1 && colums == x - 1) {
                my_putchar('o');
            } else if (rows == 0 || rows == y - 1) {
                my_putchar('-');
            } else if (colums == 0 || colums == x - 1) {
                my_putchar('|');
            } else {
                my_putchar(' ');
            }
        }
        my_putchar('\n');
}
}

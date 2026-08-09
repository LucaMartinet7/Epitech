/*
** EPITECH PROJECT, 2023
** B-AIA-200-PAR-2-2-n4s-luca.martinet
** File description:
** my_putstr.c
*/
void my_putchar(char c);
void my_putstr(const char *src)
{
    for (int i = 0; src[i] != '\0'; ++i){
        my_putchar(src[i]);
    }
}

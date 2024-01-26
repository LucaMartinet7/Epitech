/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-2-myrpg-loup.marquez
** File description:
** check_font
*/

#include "../include/my_hunter.h"
#include "../lib/my/my.h"

void check_font(sfFont *font)
{
    if (!font) {
        my_putstr("Failed to load font!");
        my_putchar('\n');
        return 1;
    }
}

sfFont* font_do(void)
{
    sfFont* font = sfFont_createFromFile("image/font/GothamMedium.ttf");
    check_font(font);
    return font;
}

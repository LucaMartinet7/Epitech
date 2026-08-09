/*
** EPITECH PROJECT, 2022
** B-MUL-200-PAR-2-2-mypaint-luca.martinet
** File description:
** menubar_pt2.c
*/

#include "../include/my.h"

int menu_bar_text3(sfRenderWindow *window)
{
    sfFont* font = sfFont_createFromFile("images/Arial.ttf");
    sfText* text = sfText_create();
    sfText_setString(text, "Help");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 24);
    sfText_setFillColor(text, sfWhite);
    sfFloatRect text_rect = sfText_getGlobalBounds(text);
    sfVector2f text_position = {170, 10};
    sfText_setPosition(text, text_position);

    sfRenderWindow_drawText(window, text, NULL);

    sfText_destroy(text);
    sfFont_destroy(font);
    return 0;
}

int menu_bar_text2(sfRenderWindow *window)
{
    sfFont* font2 = sfFont_createFromFile("images/Arial.ttf");
    sfText* text2 = sfText_create();
    sfText_setString(text2, "Edition");
    sfText_setFont(text2, font2);
    sfText_setCharacterSize(text2, 24);
    sfText_setFillColor(text2, sfWhite);
    sfFloatRect text_rect2 = sfText_getGlobalBounds(text2);
    sfVector2f text_position2 = {70, 10};
    sfText_setPosition(text2, text_position2);

    sfRenderWindow_drawText(window, text2, NULL);

    sfText_destroy(text2);
    sfFont_destroy(font2);
    return 0;
}

int menu_bar_text1(sfRenderWindow *window, sfRectangleShape *menu_bar)
{
    sfFont* font = sfFont_createFromFile("images/Arial.ttf");
    sfText* text = sfText_create();
    sfText_setString(text, "File");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 24);
    sfText_setFillColor(text, sfWhite);
    sfFloatRect text_rect = sfText_getGlobalBounds(text);
    sfVector2f text_position = {10, 10};
    sfText_setPosition(text, text_position);

    sfRenderWindow_drawRectangleShape(window, menu_bar, NULL);
    sfRenderWindow_drawText(window, text, NULL);

    sfText_destroy(text);
    sfFont_destroy(font);
    sfRectangleShape_destroy(menu_bar);
    return 0;
}

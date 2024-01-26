/*
** EPITECH PROJECT, 2022
** B-MUL-200-PAR-2-2-mypaint-luca.martinet
** File description:
** menubar.c
*/

#include "../include/my.h"

int eraser(sfRenderWindow *window)
{
    sfImage_createFromFile("images/eraser.png");
    sfTexture* texture = sfTexture_createFromFile("images/eraser.png", NULL);
    sfSprite* sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){0.1, 0.1});
    sfVector2f position = {310, 0};
    sfSprite_setPosition(sprite, position);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    return 0;
}

int paint_brush(sfRenderWindow *window)
{
    sfImage_createFromFile("images/pen.png");
    sfTexture* texture = sfTexture_createFromFile("images/pen.png", NULL);
    sfSprite* sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){0.1, 0.1});
    sfVector2f position = {240, 0};
    sfSprite_setPosition(sprite, position);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_display(window);
    return 0;
}

int menu_bar(sfRenderWindow *window)
{
    sfRectangleShape *menu_bar = sfRectangleShape_create();
    sfRectangleShape_setSize(menu_bar, (sfVector2f){800, 50});
    sfRectangleShape_setFillColor(menu_bar, sfBlack);

    menu_bar_text1(window, menu_bar);
    menu_bar_text2(window);
    menu_bar_text3(window);
    red(window);
    bleu(window);
    vert(window);
    eraser(window);
    paint_brush(window);
    red(window);
    bleu(window);
    vert(window);
    return 0;
}

/*
** EPITECH PROJECT, 2022
** B-MUL-200-PAR-2-2-mypaint-luca.martinet
** File description:
** main.c
*/

#include "../include/my.h"

int red(sfRenderWindow *window)
{
    sfImage_createFromFile("images/red.jpg");
    sfTexture* texture = sfTexture_createFromFile("images/red.jpg", NULL);
    sfSprite* sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){0.1, 0.1});
    sfVector2f position = {400, 0};
    sfSprite_setPosition(sprite, position);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    return 0;
}

int bleu(sfRenderWindow *window)
{
    sfImage_createFromFile("images/bleu.png");
    sfTexture* texture = sfTexture_createFromFile("images/bleu.png", NULL);
    sfSprite* sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){0.1, 0.1});
    sfVector2f position = {460, -30};
    sfSprite_setPosition(sprite, position);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    return 0;
}

int vert(sfRenderWindow *window)
{
    sfImage_createFromFile("images/vert.jpg");
    sfTexture* texture = sfTexture_createFromFile("images/vert.jpg", NULL);
    sfSprite* sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){0.1, 0.1});
    sfVector2f position = {545, -30};
    sfSprite_setPosition(sprite, position);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    return 0;
}

/*
** EPITECH PROJECT, 2022
** B-MUL-200-PAR-2-2-mypaint-luca.martinet
** File description:
** select_button.c
*/

#include "../include/my.h"

int select_paintbrush(sfRenderWindow *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    if (mouse.x >= 240 && mouse.x <= 290 && mouse.y >= 0 && mouse.y <= 50)
        return 1;
    return 0;
}

int select_eraser(sfRenderWindow *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    if (mouse.x >= 310 && mouse.x <= 360 && mouse.y >= 0 && mouse.y <= 50)
        return 1;
    return 0;
}

int select_red(sfRenderWindow *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    if (mouse.x >= 400 && mouse.x <= 450 && mouse.y >= 0 && mouse.y <= 50)
        return 1;
    return 0;
}

int select_bleu(sfRenderWindow *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    if (mouse.x >= 460 && mouse.x <= 510 && mouse.y >= 0 && mouse.y <= 50)
        return 1;
    return 0;
}

int select_vert(sfRenderWindow *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    if (mouse.x >= 545 && mouse.x <= 600 && mouse.y >= 0 && mouse.y <= 50)
        return 1;
    return 0;
}

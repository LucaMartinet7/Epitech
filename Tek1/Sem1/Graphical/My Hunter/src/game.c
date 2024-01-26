/*
** EPITECH PROJECT, 2022
** B-MUL-100-PAR-1-2-myhunter-luca.martinet
** File description:
** game.c
*/

#include "../include/my.h"

void move_right(void)
{
    return 0;
}

void conditions(sfEvent event, sfRenderWindow* window)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}

int game_function(sfRenderWindow* window, sfEvent event)
{
    sfTexture *bg_t = sfCf("./im/bg.jpg", NULL);
    sfSprite *bg_s = sfSprite_create();
    sfSprite_setTexture(bg_s, bg_t, sfTrue);
    sfVector2f bg_scale = {0.5, 0.5};
    sfSprite_setScale(bg_s, bg_scale);
    sfTexture *lantern_t = sfCf("./im/lantern.jpg", NULL);
    sfSprite *lantern_s = sfSprite_create();
    sfSprite_setTexture(lantern_s, lantern_t, sfTrue);
    sfVector2f lantern_scale = {0.40, 0.40};
    sfSprite_setScale(lantern_s, lantern_scale);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)){
            conditions(event, window);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, bg_s, NULL);
        sfRenderWindow_drawSprite(window, lantern_s, NULL);
        sfRenderWindow_display(window);
    }
}

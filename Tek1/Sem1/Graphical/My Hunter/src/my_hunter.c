/*
** EPITECH PROJECT, 2022
** B-MUL-100-PAR-1-2-myhunter-luca.martinet
** File description:
** my_hunter.c
*/

#include "../include/my.h"

void conditions_again(sfEvent event, sfRenderWindow* window)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}

void check_click(sfRenderWindow* window, sfEvent event)
{
    sfVector2i mouse = sfMouse_getPosition(window);
    if (event.type == sfEvtMouseButtonPressed)
        if (mouse.x >= 802 && mouse.x <= 1098
        && mouse.y >= 551 && mouse.y <= 667) {
            game_function(window, event);

    }
}

int hunter_main(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window;
    sfEvent event;
    sfTexture* main_menu_t = sfCf("./im/bg.jpg", NULL);
    sfSprite* main_menu_s = sfSprite_create();
    sfSprite* button_t = sfCf("im/play_button.jpg", NULL);
    sfSprite* button_s = sfSprite_create();
    sfVector2f main_menu_scale = {0.5, 0.5};
    sfVector2f button_scale = {0.7, 0.7};
    sfVector2f button_pos = {800, 550};
    sfSprite_setScale(main_menu_s, main_menu_scale);
    sfSprite_setPosition(button_s, button_pos);
    sfSprite_setTexture(main_menu_s, main_menu_t, sfTrue);
    sfSprite_setTexture(button_s, button_t, sfTrue);
    window = sfWc(mode, "my hunter", sfResize | sfClose, NULL);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)){
            conditions_again(event, window);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, main_menu_s, NULL);
        sfRenderWindow_drawSprite(window, button_s, NULL);
        sfRenderWindow_display(window);
        check_click(window, event);
    }
}

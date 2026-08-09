/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-2-myrpg-loup.marquez
** File description:
** extra_main
*/

#include "../include/my_hunter.h"
#include "../lib/my/my.h"

void check_closed(name_t name)
{
    if (name.event.type == sfEvtClosed) {
        sfRenderWindow_close(name.window);
    }
}

void draw_everything(name_t name)
{
    sfRenderWindow_clear(name.window, sfBlack);
    sfRenderWindow_drawSprite(name.window, name.background, NULL);
    sfRenderWindow_drawSprite(name.window, name.button, NULL);
    sfRenderWindow_drawSprite(name.window, name.button2, NULL);
    menu_start_bouton_click(name.window, name.event, name);
    menu_quit_bouton_click(name.window, name.event, name);
}

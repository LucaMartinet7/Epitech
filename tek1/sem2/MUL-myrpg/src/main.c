/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** aa
*/

#include "../include/my_hunter.h"
#include <unistd.h>

void menu_start_bouton_click(sfRenderWindow* window, sfEvent event,
name_t *name)
{
    sfVector2i mouse_position = sfMouse_getPosition(window);
    if (mouse_position.x >= 869 && mouse_position.y >= 399 &&
    mouse_position.x <= 1020 && mouse_position.y <= 450) {
        if (event.type == sfEvtMouseButtonPressed)
            game_init_mouv(window, event);
    }
}

void menu_quit_bouton_click(sfRenderWindow* window, sfEvent event, name_t *name)
{
    sfVector2i mouse_position = sfMouse_getPosition(window);
    if (mouse_position.x >= 870 && mouse_position.y >= 580 &&
    mouse_position.x <= 1018 && mouse_position.y <= 634) {
        if (event.type == sfEvtMouseButtonPressed)
            sfRenderWindow_close(window);
    }
}

void create_sprite(name_t *name)
{
    name->texture0 = sfTexture_createFromFile
    ("./image/map/homescreen2.png", NULL);
    name->background = sfSprite_create();
    name->texture1 = sfTexture_createFromFile
    ("./image/menu/start.png", NULL);
    name->button = sfSprite_create();
    name->texture2 = sfTexture_createFromFile
    ("./image/menu/quitt.png", NULL);
    name->button2 = sfSprite_create();

}

int menu_init(name_t *name)
{
    create_sprite(name);
    sfVector2f position_b = {800, 375};
    sfVector2f position_b2 = {865, 575};
    sfSprite_setScale(name->background, (sfVector2f){1, 0.95});
    sfSprite_setTexture(name->background, name->texture0, sfTrue);

    sfSprite_setTexture(name->button, name->texture1, sfTrue);
    sfSprite_setPosition(name->button, position_b);
    sfSprite_setScale(name->button, (sfVector2f){1.5, 1.5});

    sfSprite_setTexture(name->button2, name->texture2, sfTrue);
    sfSprite_setPosition(name->button2, position_b2);
    sfSprite_setScale(name->button2, (sfVector2f){1.1, 1.1});
    return 0;
}

int main(void)
{
    name_t name;
    menu_init(&name);
    sfVideoMode video_mode = {1920, 1080, 32};
    name.window = sfRenderWindow_create
    (video_mode,"My_rpg", sfClose | sfResize, NULL);
    if (!name.window)
    return (EXIT_FAILURE);
    sfRenderWindow_setFramerateLimit(name.window, 30);

    while (sfRenderWindow_isOpen(name.window)) {
        sfRenderWindow_display(name.window);
        while (sfRenderWindow_pollEvent(name.window, &name.event)) {
            check_closed(name);
        }
        draw_everything(name);
    }
    return 0;
}

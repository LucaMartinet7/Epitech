/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** aa
*/

#include "../include/my_hunter.h"
#include <unistd.h>

void mouvement_up(name_t *name)
{
    name->rect1 = sfSprite_getTextureRect(name->my_sprite_up);
    name->rect1.height = 64;
    name->rect1.left = 0;
    name->rect1.top = 0;
    name->rect1.width = 67;
    sfSprite_setTextureRect(name->my_sprite_up, name->rect1);
}

void mouvement_down(name_t *name)
{
    name->rect2 = sfSprite_getTextureRect(name->my_sprite_down);
    name->rect2.height = 64;
    name->rect2.left = 0;
    name->rect2.top = 0;
    name->rect2.width = 73;
    sfSprite_setTextureRect(name->my_sprite_down, name->rect2);
}

void boucle(name_t *name, sfRenderWindow *window, sfEvent event,
sfSprite *background1, sfSprite *button_battle)
{
    float speed = 5.f;
    sfVector2f velocity = {0.f, 0.f};

    mouvement_up(name);
    mouvement_down(name);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            } else if (event.type == sfEvtKeyPressed) {
                switch (event.key.code) {
                    case sfKeyUp:
                        velocity.y = -speed/2;
                        name->rect1.left += 64;
                        if (name->rect1.left == 384) {
                            name->rect1.left = 0;
                        }
                        sfSprite_setTextureRect(name->my_sprite_up, name->rect1);
                        break;
                    case sfKeyDown:
                        velocity.y = speed/2;
                        name->rect2.left += 64;
                        if (name->rect2.left == 384) {
                            name->rect2.left = 0;
                        }
                        sfSprite_setTextureRect(name->my_sprite_down, name->rect2);
                        break;
                    case sfKeyLeft:
                        velocity.x = -speed/2;
                        name->rect1.left += 64;
                        if (name->rect1.left == 384) {
                            name->rect1.left = 0;
                        }
                        sfSprite_setTextureRect(name->my_sprite_down, name->rect1);
                        break;
                    case sfKeyRight:
                        velocity.x = speed/2;
                        name->rect1.left += 64;
                        if (name->rect1.left == 384) {
                            name->rect1.left = 0;
                        }
                        sfSprite_setTextureRect(name->my_sprite_down, name->rect1);
                        break;
                    default:
                        break;
                }
            } else if (event.type == sfEvtKeyReleased) {
                switch (event.key.code) {
                    case sfKeyUp:
                    case sfKeyDown:
                        velocity.y = 0.f;
                        break;
                    case sfKeyLeft:
                    case sfKeyRight:
                        velocity.x = 0.f;
                        break;
                    default:
                        break;
                }
            }
        }
        sfVector2f position = sfSprite_getPosition(name->my_sprite_up);
        position.x += velocity.x;
        position.y += velocity.y;
        sfSprite_setPosition(name->my_sprite_up, position);
        sfSprite_setPosition(name->my_sprite_down, position);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, background1, NULL);
        sfRenderWindow_drawSprite(window, name->my_sprite_up, NULL);
        sfRenderWindow_drawSprite(window, name->my_sprite_down, NULL);
        sfRenderWindow_drawSprite(window, button_battle, NULL);
        start_battle_button(window, event);
    }
}

void game_init_mouv(sfRenderWindow* window, sfEvent event, name_t *name)
{
    sfTexture* texture2 = sfTf("./image/map/maphouserpg.png", NULL);
    sfSprite* background1 = sfSprite_create();
    sfSprite_setScale(background1, (sfVector2f){1.5, 1.5});
    sfSprite_setPosition(background1, (sfVector2f){350, 75});
    sfSprite_setTexture(background1, texture2, sfTrue);

    sfTexture* texture3 = sfTf("./image/character/face_up.png", NULL);
    name->my_sprite_up = sfSprite_create();
    sfSprite_setTexture(name->my_sprite_up, texture3, sfTrue);

    sfTexture* texture4 = sfTf("./image/character/face_down.png", NULL);
    name->my_sprite_down = sfSprite_create();
    sfSprite_setTexture(name->my_sprite_down, texture4, sfTrue);

    sfVector2f position_s = {960 - 260, 540 - 145};
    sfSprite_setPosition(name->my_sprite_up, position_s);
    sfSprite_setPosition(name->my_sprite_down, position_s);

    sfTexture* Text_button_battle = sfTf("./image/items/battle_button.png", NULL);
    sfSprite* button_battle = sfSprite_create();
    sfSprite_setScale(button_battle, (sfVector2f){1.5, 1.5});
    sfSprite_setPosition(button_battle, (sfVector2f){620, 390});
    sfSprite_setTexture(button_battle, Text_button_battle, sfTrue);
    boucle(name, window, event, background1, button_battle);
}

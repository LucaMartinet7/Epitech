/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** battle
*/

#include "../include/my_hunter.h"
#include "../lib/my/my.h"
#include <stdlib.h>

game_data game_info(void)
{
    game_data data;

    data.score = 0;
    data.life = 3;
    data.info = 4;
    return (data);
}

sf_data initialize_sf_data(void)
{
    sf_data sf_info;
    sf_info.texture_char =
    sfTexture_createFromFile("image/character/BirdSprite.png", NULL);
    sf_info.sprite_char = sfSprite_create();
    return sf_info;
}

sfText* initialize_text_score(sf_data sf_info, game_data data, sfFont* font)
{
    sfText* text = sfText_create();
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 24);
    my_strcpy(sf_info.info_text, "Score: ");
    int_to_string(data.score, sf_info.info_text + my_strlen(sf_info.info_text));
    sfText_setString(text, sf_info.info_text);
    sfColor color = sfBlue;
    sfText_setFillColor(text, color);
    sf_info.text_pos = (sfVector2f){10, 10};
    sfText_setPosition(text, sf_info.text_pos);
    return text;
}

sfText* initialize_text_life(sf_data sf_info, game_data data, sfFont* font)
{
    sfText* text_life = sfText_create();
    sfText_setFont(text_life, font);
    sfText_setCharacterSize(text_life, 24);
    my_strcpy(sf_info.info_text_life, "Life: ");
    int_to_string(data.life, sf_info.info_text_life +
    my_strlen(sf_info.info_text_life));
    sfText_setString(text_life, sf_info.info_text_life);
    sfColor color = sfGreen;
    sfText_setFillColor(text_life, color);
    sf_info.text_pos_life = (sfVector2f){20, 10};
    sfText_setPosition(text_life, sf_info.text_pos_life);
    return text_life;
}

void start_battle_button(sfRenderWindow* window, sfEvent event)
{
    sfVector2i mouse_position_window = sfMouse_getPosition(NULL);
    if (mouse_position_window.x >= 620 && mouse_position_window.x <= 643 &&
        mouse_position_window.y >= 456 && mouse_position_window.y <= 476) {
        if (event.type == sfEvtMouseButtonPressed) {
            init_battle(window, event);
        }
    }
}

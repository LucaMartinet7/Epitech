/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-2-myrpg-loup.marquez
** File description:
** battle_3
*/

#include "../include/my_hunter.h"
#include "../lib/my/my.h"

void mouse_event(sfMouseButtonEvent event, sfVector2f *position,
sfRenderWindow *window, game_data *data)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if (event.button == sfMouseLeft) {
            mouse_cond(event, position, window, data);
        }
    }
}

void poll_event(sfRenderWindow *window, sfVector2f *position, game_data *data)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            mouse_event(event.mouseButton, position,
            window, data);
        }
    }
}

void update_game_info(sf_data sf_info, game_data data, sfText* text,
sfText* text_life)
{
    my_strcpy(sf_info.info_text, "Score: ");
    int_to_string(data.score, sf_info.info_text + my_strlen(sf_info.info_text));
    sfText_setString(text, sf_info.info_text);
    sfText_setPosition(text, sf_info.text_pos);

    my_strcpy(sf_info.info_text_life, "Life: ");
    int_to_string(data.life, sf_info.info_text_life +
    my_strlen(sf_info.info_text_life));
    sfText_setString(text_life, sf_info.info_text_life);
    sfText_setPosition(text_life, sf_info.text_pos_life);

    sfVector2f text_life_pos = sf_info.text_pos_life;
    text_life_pos.y += 30;
    sfText_setPosition(text_life, text_life_pos);

    sfSprite_setTexture(sf_info.sprite_char, sf_info.texture_char, sfTrue);
    sfSprite_setTextureRect(sf_info.sprite_char, sf_info.rect);
    sfSprite_setPosition(sf_info.sprite_char, sf_info.position);
}

void battle(sfRenderWindow* window, sfEvent event, sf_data sf_info, game_data data, sfSprite* background_battle, sfText* text, sfText* text_life, sfClock* clock, float seconds)
{
    while (sfRenderWindow_isOpen(window)) {
        sf_info.time = sfClock_getElapsedTime(clock);
        seconds = sf_info.time.microseconds / 100000.0;
        if (seconds > 1) {
            move_rect(&sf_info.rect, 110, 330);
            sfClock_restart(clock);
        }
        data.info = move_pos(&sf_info.position, &sf_info.rect, data.info);
        sfRenderWindow_setFramerateLimit(window, 60);
        poll_event(window, &sf_info.position, &data);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, background_battle, NULL);
        update_game_info(sf_info, data, text, text_life);
        sfRenderWindow_drawSprite(window, sf_info.sprite_char, NULL);
        sfRenderWindow_drawText(window, text_life, NULL);
        sfRenderWindow_drawText(window, text, NULL);
        }
}

void init_battle(sfRenderWindow* window, sfEvent event)
{
    sfTexture* texture_battle = sfTf("./image/map/maprpgnight.png", NULL);
    sfSprite* background_battle = sfSprite_create();
    sfSprite_setScale(background_battle, (sfVector2f){1.5, 1.5});
    sfSprite_setPosition(background_battle, (sfVector2f){350, 75});
    sfSprite_setTexture(background_battle, texture_battle, sfTrue);
    sf_data sf_info = initialize_sf_data();
    game_data data = game_info();
    sf_info.rect = (sfIntRect){0, 0, 15, 15};
    sf_info.position = (sfVector2f){-10, rand_nb()};
    sfFont* font = font_do();
    sfText* text =  initialize_text_score(sf_info, data, font);
    sfText* text_life = initialize_text_life(sf_info, data, font);
    sfClock* clock;
    float seconds;
    clock = sfClock_create();
    battle(window, event, sf_info, data, background_battle,
    text, text_life, clock, seconds);
}

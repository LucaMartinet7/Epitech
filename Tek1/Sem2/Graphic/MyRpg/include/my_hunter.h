/*
** EPITECH PROJECT, 2022
** my_include
** File description:
** aa
*/

#pragma once

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Clock.h>
#include <stdio.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>

#define sfTf sfTexture_createFromFile
#define sfCf sfTexture_createFromFile
#define sfWc sfRenderWindow_creates
typedef struct name {
    sfTexture* texture0;
    sfSprite* background;
    sfTexture* texture1;
    sfSprite* button;
    sfTexture* texture2;
    sfSprite* button2;
    sfTexture* texture3;
    sfSprite* button3;
    sfRenderWindow* window;
    sfEvent event;
    sfIntRect rect1;
    sfIntRect rect2;
    sfSprite* my_sprite_up;
    sfSprite* my_sprite_down;
}name_t;

typedef struct data {
int score;
int life;
int info;
} game_data;

typedef struct sf_info{
    sfTexture *texture_char;
    sfSprite *sprite_char;
    sfTime time;
    char info_text[256];
    sfVector2f text_pos;
    char info_text_life[256];
    sfVector2f text_pos_life;
    sfIntRect rect;
    sfVector2f position;
} sf_data;

//battle
sf_data initialize_sf_data(void);
sfText* initialize_text_score(sf_data sf_info, game_data data, sfFont* font);
void get_position(sfRenderWindow* Window);
void start_battle_button(sfRenderWindow* window, sfEvent event);
void int_to_string(int value, char* buffer);
void move_rect(sfIntRect *rect, int offset, int max_value);
sfText* initialize_text_life(sf_data sf_info, game_data data, sfFont* font);
void init_battle(sfRenderWindow* window, sfEvent event);
game_data game_info(void);
//main
void draw_everything(name_t name);
void check_closed(name_t name);
//mouvement
void mouse_cond(sfMouseButtonEvent event, sfVector2f *position,
sfRenderWindow *window, game_data *data);
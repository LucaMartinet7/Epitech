/*
** EPITECH PROJECT, 2022
** B-MUL-200-PAR-2-2-mypaint-luca.martinet
** File description:
** my_paint.h
*/

#pragma once
#include <unistd.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>

typedef struct my_paint_s {
    sfBool is_mouse_pressed;
    sfBool is_pen;
    sfBool is_eraser;
    sfVector2f start_position;
    sfColor selected_colour;
    sfEvent event;
} my_paint;

//menu bar
int menu_bar(sfRenderWindow *window);
int menu_bar_text1(sfRenderWindow *window, sfRectangleShape *menu_bar);
int menu_bar_text2(sfRenderWindow *window);
int menu_bar_text3(sfRenderWindow *window);
int paint_brush(sfRenderWindow *window);
int eraser(sfRenderWindow *window);

//coloration
int red(sfRenderWindow *window);
int bleu(sfRenderWindow *window);
int vert(sfRenderWindow *window);

//select button
int select_eraser(sfRenderWindow *window);
int select_paintbrush(sfRenderWindow *window);
int select_red(sfRenderWindow *window);
int select_bleu(sfRenderWindow *window);
int select_vert(sfRenderWindow *window);

//extra
void clear_window(sfRenderWindow *window);
void drawing_case(my_paint *paint, sfRenderWindow *window,
sfTexture *canvas_texture);
void if_cases(my_paint *paint, sfRenderWindow *window);

/*
** EPITECH PROJECT, 2022
** B-MUL-200-PAR-2-2-mypaint-luca.martinet
** File description:
** main.c
*/

#include "../include/my.h"

sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {800, 600, 60};
    sfRenderWindow *window;
    window = sfRenderWindow_create(mode, "My_Paint", sfResize | sfClose, NULL);
    return window;
}

void init_struct(my_paint *paint)
{
    paint->selected_colour = sfBlack;
    paint->start_position = (sfVector2f){0, 0};
    paint->is_mouse_pressed = sfFalse;
    paint->is_pen = sfFalse;
    paint->is_eraser = sfFalse;
}

void switch_case(my_paint *paint, sfRenderWindow *window,
sfTexture *canvas_texture, sfSprite *canvas_sprite)
{
    switch (paint->event.type) {
        case sfEvtClosed:
            sfRenderWindow_close(window);
            break;
        case sfEvtMouseButtonPressed:
            paint->is_mouse_pressed = sfTrue;
            paint->start_position.x = paint->event.mouseButton.x;
            paint->start_position.y = paint->event.mouseButton.y;
            if_cases(paint, window);
        break;
        case sfEvtMouseButtonReleased:
            paint->is_mouse_pressed = sfFalse;
            break;
        case sfEvtMouseMoved:
            drawing_case(paint, window, canvas_texture);
                break;
            }
}

void game_loop(sfRenderWindow* window, sfTexture* canvas_texture,
sfSprite* canvas_sprite, my_paint *paint)
{
    while (sfRenderWindow_isOpen(window)) {
        menu_bar(window);
        while (sfRenderWindow_pollEvent(window, &paint->event)) {
            switch_case(paint, window, canvas_texture, canvas_sprite);
        }
        sfRenderWindow_drawSprite(window, canvas_sprite, NULL);
    }
}

int main(void)
{
    my_paint paint = {0};
    init_struct(&(paint));
    sfRenderWindow *window = create_window();
    sfImage *background = sfImage_createFromColor(800, 600, sfWhite);
    sfTexture* canvas_texture = sfTexture_create(800, 600);
    sfSprite* canvas_sprite = sfSprite_create();
    sfSprite_setTexture(canvas_sprite, canvas_texture, sfTrue);
    sfTexture_updateFromImage(canvas_texture, background, 0, 0);
    sfImage_destroy(background);
    game_loop(window, canvas_texture, canvas_sprite, &(paint));
    clear_window(window);
    sfRenderWindow_destroy(window);
    sfTexture_destroy(canvas_texture);
    sfSprite_destroy(canvas_sprite);
    return 0;
}

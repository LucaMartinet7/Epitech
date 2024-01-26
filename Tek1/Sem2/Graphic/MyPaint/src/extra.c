/*
** EPITECH PROJECT, 2022
** B-MUL-200-PAR-2-2-mypaint-luca.martinet
** File description:
** extra.c
*/

#include "../include/my.h"

void clear_window(sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfWhite);
}

void if_cases(my_paint *paint, sfRenderWindow *window)
{
    if (select_paintbrush(window)) {
        paint->is_eraser = sfFalse;
        paint->is_pen = sfTrue;
        paint->selected_colour = sfBlack;
        } if (select_eraser(window)) {
        paint->is_pen = sfFalse;
        paint->is_eraser = sfTrue;
        paint->selected_colour = sfWhite;
        } if (select_red(window)) {
        paint->is_pen = sfTrue;
        paint->selected_colour = sfRed;
    } if (select_bleu(window)) {
        paint->is_pen = sfTrue;
        paint->selected_colour = sfBlue;
    } if (select_vert(window)) {
        paint->is_pen = sfTrue;
        paint->selected_colour = sfGreen;
    }
}

void drawing_case(my_paint *paint, sfRenderWindow *window,
sfTexture *canvas_texture)
{
    if (paint->is_mouse_pressed && paint->event.mouseMove.x >= 0 &&
        paint->event.mouseMove.x <= 800 && paint->event.mouseMove.y >= 50 &&
        paint->event.mouseMove.y <= 600) {
        sfVertexArray* line = sfVertexArray_create();
        sfVertex vertex1 = {paint->start_position, paint->selected_colour};
        sfVertex vertex2 = {{paint->event.mouseMove.x,
        paint->event.mouseMove.y}, paint->selected_colour};
        sfVertexArray_append(line, vertex1);
        sfVertexArray_append(line, vertex2);
        sfVertexArray_setPrimitiveType(line, sfLines);
        sfRenderWindow_drawVertexArray(window, line, NULL);
        sfTexture_updateFromRenderWindow(canvas_texture, window, 0, 0);
        paint->start_position = vertex2.position;
        sfVertexArray_destroy(line);
        }
}

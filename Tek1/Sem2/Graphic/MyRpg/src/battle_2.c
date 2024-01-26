/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-2-myrpg-loup.marquez
** File description:
** battle_2
*/

#include "../include/my_hunter.h"
#include "../lib/my/my.h"

void int_to_string(int value, char* buffer)
{
    int i = 0;
    int is_negative = 0;
    if (value < 0) {
        is_negative = 1;
        value = -value;
    }
    do {
        buffer[i++] = '0' + (value % 10);
        value /= 10;
    } while (value);
    if (is_negative) {
        buffer[i++] = '-';
    }
    buffer[i] = '\0';
    for (int j = 0, k = i - 1; j < k; j++, k--) {
        char temp = buffer[j];
        buffer[j] = buffer[k];
        buffer[k] = temp;
    }
}

int rand_nb(void)
{
    int rand_nb = rand() % 400 + 10;
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left == max_value)
        rect->left = 0;
}

int move_pos(sfVector2f *position, sfIntRect *rect, int i)
{
    position->x += i;
    if (position->x >= 1800) {
        rect->top = 110;
        i = -i;
    }
    if (position->x <= -200) {
        rect->top = 0;
        i = -i;
    }
    return (i);
}

void mouse_cond(sfMouseButtonEvent event, sfVector2f *position,
sfRenderWindow *window, game_data *data)
{
    int rand = rand_nb();
    if (event.x >= position->x && event.x <= position->x + 110
                && event.y >= position->y && event.y <= position->y + 110) {
                position->x = -200;
                position->y = rand;
                data->score = data->score + 100;
                data->info += 1;
            } else if (data->life > 0) {
                data->life = data->life - 1;
            }
            if (data->life == 0) {
                my_putstr("GAME OVER");
                my_putchar('\n');
                game_init_mouv(window, event);
            }
            if (data->score == 300) {
                my_putstr("Win");
                my_putchar('\n');
                game_init_mouv(window, event);
            }
}

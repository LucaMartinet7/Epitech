/*
** EPITECH PROJECT, 2022
** B-MUL-100-PAR-1-2-myradar-luca.martinet
** File description:
** my_radar.c
*/

#include "../include/my.h"

#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <stddef.h>

sfCircleShape *create_circle(sfVector2f pos, float radius)
{
    sfCircleShape* sfCircleShape_create(void);
}

int main(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window;
    sfEvent event;

    window = sfWc(mode, "my radar", sfResize | sfClose, NULL);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)){
            conditions_again(event, window);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_display(window);
    }
}
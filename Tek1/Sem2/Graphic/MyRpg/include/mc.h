/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-2-myrpg-loup.marquez
** File description:
** mc
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


#define sfCf sfTexture_createFromFile
#define sfWc sfRenderWindow_creates
void get_position(sfRenderWindow* Window);

typedef struct name {
    sfTexture* texture0;
    sfSprite* background;
    sfTexture* texture1;
    sfSprite* button;
    sfTexture* texture2;
    sfSprite* button2;
    sfRenderWindow* window;
    sfEvent event;
}name_t;

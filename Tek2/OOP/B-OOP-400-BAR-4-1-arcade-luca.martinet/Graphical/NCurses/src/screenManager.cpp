/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** screenManager
*/

#include "ArcadeNCurses.hpp"

void arcade::ArcadeNCurses::display(const data_t &data)
{
    int tileSize = 1;
    int startX = (data.size.first) / 2;
    int startY = (data.size.second) / 2;
    int posX = 0;
    int posY = 0;

    erase();
    for (auto &obj : data.objects) {
        if (obj->getType() == arcade::Type::Text) {
            posX = startX + obj->getPos()[0] * tileSize;
            posY = startY + obj->getPos()[1] * tileSize;
            int r = obj->getRGB()[0];
            int g = obj->getRGB()[1];
            int b = obj->getRGB()[2];
            int color_pair = (r * 6 / 256) + (g * 6 / 256) * 6 + (b * 6 / 256) * 6 * 6 + 1;
            init_pair(color_pair, COLOR_WHITE, COLOR_BLACK);
            attron(COLOR_PAIR(color_pair) | A_DIM);
            mvprintw(posY, posX, obj->getAsset().c_str());
            attroff(COLOR_PAIR(color_pair) | A_DIM);
        } else {
            posX = startX + obj->getPos()[0] * tileSize;
            posY = startY + obj->getPos()[1] * tileSize;
            attron(COLOR_PAIR(1));
            for (int i = 0; i < obj->getSize()[0] * tileSize; i++) {
                for (int j = 0; j < obj->getSize()[1] * tileSize; j++) {
                    mvaddch(posY + j, posX + i, obj->getAscii());
                }
            }
            attroff(COLOR_PAIR(1));
        }
    }
    refresh();
}

void arcade::ArcadeNCurses::clear(void)
{
    erase();
}

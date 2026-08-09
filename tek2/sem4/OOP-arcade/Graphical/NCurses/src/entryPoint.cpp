/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** entryPoint
*/

#include <memory>

#include "ArcadeNCurses.hpp"

extern "C" std::unique_ptr<arcade::IDisplayModule> entryPoint()
{
    return std::make_unique<arcade::ArcadeNCurses>();
}

arcade::ArcadeNCurses::ArcadeNCurses()
{
    initscr();
    cbreak();
    nodelay(stdscr, TRUE);
    raw();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLUE);
    init_pair(2, COLOR_GREEN, COLOR_BLUE);
    setKeyMap();
}

arcade::ArcadeNCurses::~ArcadeNCurses()
{
    endwin();
}

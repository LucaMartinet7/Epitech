/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** utils
*/

#include <iostream>

bool is_display_lib(const std::string &filename)
{
    std::string libPath = filename.substr(filename.find_last_of('/') + 1);

    return (libPath == "arcade_ndk++.so" || libPath == "arcade_aalib.so" ||
            libPath == "arcade_libcaca.so" || libPath == "arcade_allegro5.so" ||
            libPath == "arcade_xlib.so" || libPath == "arcade_gtk+.so" ||
            libPath == "arcade_sfml.so" || libPath == "arcade_irrlicht.so" ||
            libPath == "arcade_opengl.so" || libPath == "arcade_vulkan.so" ||
            libPath == "arcade_qt5.so" || libPath == "arcade_sdl2.so" ||
            libPath == "arcade_ncurses.so");
}

bool is_game_lib(const std::string &filename)
{
    std::string libPath = filename.substr(filename.find_last_of('/') + 1);

    return (libPath == "arcade_snake.so" || libPath == "arcade_pacman.so" ||
            libPath == "arcade_sokoban.so" || libPath == "arcade_nibbler.so" ||
            libPath == "arcade_qix.so" || libPath == "arcade_centipede.so" ||
            libPath == "arcade_solarfox.so");
}

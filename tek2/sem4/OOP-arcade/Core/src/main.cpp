/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** main
*/

#include "Core.hpp"

#include <iostream>

int main(int ac, char **av)
{
    arcade::Core core;
    if (ac != 2) {
        std::cerr << "Usage: ./arcade path_to_graphic_library" << std::endl;
        return 84;
    }

    if (!is_display_lib(av[1])) {
        std::cerr << "Invalid graphic library" << std::endl;
        return 84;
    }

    core.init(av[1]);
    core.loop();
}

/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-raytracer-jules.dufraiche
** File description:
** main
*/

#include <iostream>
#include <fstream>

#include "raytracer.hpp"
#include "Config.hpp"
#include "Error.hpp"

static int print_h(void)
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t./raytracer [config_file]" << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\tconfig_file\tfile with the configuration of the raytracer" << std::endl;
    return SUCCESS;
}

static int print_usage(void)
{
    std::cerr << "Usage: ./Raytracer <cfg_file> (filename)" << std::endl;
    return ERROR;
}

int main(int ac, char **av)
{
    if (ac != 2 && ac != 3)
        return print_usage();
    if (std::string(av[1]) == "-h" || std::string(av[1]) == "--help")
        return print_h();
    try {
        std::string file_path(av[1]);
        raytracer::Config config(file_path);
    } catch (std::exception &e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return 84;
    }
    return SUCCESS;
}

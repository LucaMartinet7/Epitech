/*
** EPITECH PROJECT, 2024
** B-YEP-400-BAR-4-1-zappy-noe.kurata
** File description:
** main
*/

#include "Client.hpp"
#include "SfmlGame.hpp"

int main(int ac, char **av)
{
    if (ac != 3) {
        std::cerr << "Usage: ./zappy_gui [ip] [port]" << std::endl;
        return 84;
    }
    Client client(av[1], std::stoi(av[2]));
    SfmlGame game;

    if (!client.connect()) {
        std::cerr << "Failed to connect to server" << std::endl;
        return 84;
    }
    while (game.isWindowOpen()) {
        client.receiveData();
    }

    return 0;
}

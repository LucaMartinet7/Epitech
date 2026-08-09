/*
** EPITECH PROJECT, 2024
** B-YEP-400-BAR-4-1-zappy-noe.kurata
** File description:
** SfmlClent
*/

#include "Client.hpp"
#include <iostream>

Client::Client(const std::string& serverIp, unsigned short serverPort)
    : serverIp(serverIp), serverPort(serverPort), socket()
{
    parseMap['V'] = &Client::parseVoid;
    parseMap['P'] = &Client::parsePlayers;
    parseMap['E'] = &Client::parseEvolution;
    parseMap['G'] = &Client::parseGems;
}

bool Client::connect()
{
    if (socket.connect(serverIp, serverPort) != sf::Socket::Done) {
        return false;
    }
    return true;
}

/*
** EPITECH PROJECT, 2024
** B-YEP-400-BAR-4-1-zappy-noe.kurata
** File description:
**
*/

#include "Client.hpp"
#include <sstream>

void Client::parseTile(const std::string& content, Tile& tile)
{
    std::istringstream tileStream(content);
    std::string token;
    while (std::getline(tileStream, token, ',')) {
        char type = token.front();
        if (parseMap.find(type) != parseMap.end()) {
            (this->*parseMap[type])(tile, token);
        }
    }
}

void Client::parseVoid(Tile& tile, const std::string& token)
{
    tile.isVoid = true;
}

void Client::parsePlayers(Tile& tile, const std::string& token)
{
    tile.players = std::stoi(token.substr(1));
}

void Client::parseEvolution(Tile& tile, const std::string& token)
{
    tile.evolution = std::stoi(token.substr(1));
}

void Client::parseGems(Tile& tile, const std::string& token)
{
    std::string gemType = token.substr(1, 1);
    int gemCount = std::stoi(token.substr(2));
    tile.gems[gemType] = gemCount;
}

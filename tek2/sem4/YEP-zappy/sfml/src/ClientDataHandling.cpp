/*
** EPITECH PROJECT, 2024
** B-YEP-400-BAR-4-1-zappy-noe.kurata
** File description:
**
*/

#include "Client.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

void Client::parseSingleTile(const std::string& tileContent, int row, int col)
{
    if (!tileContent.empty()) {
        Tile tile;
        parseTile(tileContent, tile);
        map[row][col] = tile;
    }
}

void Client::receiveData()
{
    std::ifstream file("../../../map.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open map file." << std::endl;
        return;
    }

    std::string gameState((std::istreambuf_iterator<char>(file)),
                           std::istreambuf_iterator<char>());

    parseGameState(gameState);
}

void Client::parseGameState(const std::string& gameState)
{
    auto [rows, cols] = parseSize(gameState);
    map.resize(rows, std::vector<Tile>(cols));
    parseGameMap(gameState, rows);
}

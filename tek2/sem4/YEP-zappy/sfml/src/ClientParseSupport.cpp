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

std::pair<int, int> Client::parseSize(const std::string& gameState)
{
    std::istringstream iss(gameState);
    std::string line;
    std::getline(iss, line, ';');
    std::istringstream sizeStream(line);
    int rows, cols;
    char sep;
    sizeStream >> rows >> sep >> cols;
    return {rows, cols};
}

void Client::parseGameMap(const std::string& gameState, int rows)
{
    std::istringstream iss(gameState);
    std::string line;
    std::getline(iss, line);
    for (int currentRow = 0; currentRow < rows && std::getline(iss, line, ';');
        ++currentRow) {
        if (line == "END") break;
        parseMapLine(line, currentRow);
    }
}

void Client::parseMapLine(const std::string& line, int currentRow)
{
    std::istringstream lineStream(line);
    std::string tileContent;
    for (int currentCol = 0; std::getline(lineStream, tileContent, '}');
        ++currentCol) {
        if (!tileContent.empty() && tileContent.front() == '{') {
            parseSingleTile(tileContent.substr(1), currentRow, currentCol);
        }
    }
}

/*
** EPITECH PROJECT, 2024
** B-YEP-400-BAR-4-1-zappy-noe.kurata
** File description:
** Client
*/

#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <SFML/Network.hpp>
#include "Tile.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <map>
#include <utility>

class Client {
    private:
        std::string serverIp;
        unsigned short serverPort;
        sf::TcpSocket socket;
        std::vector<std::vector<Tile>> map;

        typedef void (Client::*ParseFunction)(Tile&, const std::string&);
        std::map<char, ParseFunction> parseMap;

        void parseVoid(Tile& tile, const std::string& token);
        void parsePlayers(Tile& tile, const std::string& token);
        void parseEvolution(Tile& tile, const std::string& token);
        void parseGems(Tile& tile, const std::string& token);

        // Updated and new function declarations
        std::pair<int, int> parseSize(const std::string& gameState);
        void parseSingleTile(const std::string& tileContent, int row, int col);
        void parseGameMap(const std::string& gameState, int rows);
        void parseMapLine(const std::string& line, int currentRow);

    public:
        Client(const std::string& serverIp, unsigned short serverPort);
        bool connect();
        void receiveData();
        void parseGameState(const std::string& gameState);
        void parseTile(const std::string& content, Tile& tile);
        const std::vector<std::vector<Tile>>& getMap() const;
};

#endif // CLIENT_HPP

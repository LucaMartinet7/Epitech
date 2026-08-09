/*
** EPITECH PROJECT, 2024
** B-YEP-400-BAR-4-1-zappy-noe.kurata
** File description:
** SfmlGame
*/



#ifndef SFMLGAME_HPP_
    #define SFMLGAME_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <vector>

#include "Tile.hpp"
#include "Client.hpp"

class SfmlGame {
    public:
        SfmlGame();
        ~SfmlGame();
        void init();
        void draw();
        void update();
        bool isWindowOpen();
        void createTiles(std::pair<int, int> dimensions);

    protected:
        sf::RenderWindow _window;
        sf::Event _event;
        sf::Color _bgColor;
        std::vector<Tile> _map;

};

#endif /* !SFMLGAME_HPP_ */

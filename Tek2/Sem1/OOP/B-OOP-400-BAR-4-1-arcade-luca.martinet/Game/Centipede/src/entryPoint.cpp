/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** entrypoint
*/

#include <memory>

#include "CentipedeGame.hpp"
#include "AObject.hpp"
#include "AEvent.hpp"

extern "C" std::unique_ptr<arcade::IGameModule> entryPoint()
{
    return std::make_unique<arcade::CentipedeGame>();
}

arcade::CentipedeGame::CentipedeGame()
{
    srand(time(NULL));
    createMap();
    _playerPos = {MAP_SIZE_X / 2, static_cast<int>(MAP_SIZE_Y * 0.8 + 1)};
    _lastIteranceTime = std::chrono::system_clock::now();
    _charDir = static_cast<arcade::Direction>(rand() % 4);
    _lazerPos = {-1, -1};
    _fired = false;
    _points = 0;
    _it = 0;
    _centipedePos.push_back({MAP_SIZE_X / 2, static_cast<int>(MAP_SIZE_Y * 0.2 + 1)});
    _centipedeDir = arcade::Direction::RIGHT;
    for (int i = 1; i < CENTIPEDE_LEN; ++i)
        _centipedePos.push_back({_centipedePos[i - 1][0] + 1, _centipedePos[i - 1][1]});
}

arcade::CentipedeGame::~CentipedeGame()
{
    _map.objects.clear();
}

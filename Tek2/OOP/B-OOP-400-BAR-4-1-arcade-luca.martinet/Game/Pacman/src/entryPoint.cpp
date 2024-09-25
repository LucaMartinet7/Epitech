/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** entrypoint
*/

#include <memory>

#include "PacmanGame.hpp"

extern "C" std::unique_ptr<arcade::IGameModule> entryPoint()
{
    return std::make_unique<arcade::PacmanGame>();
}

arcade::PacmanGame::PacmanGame()
{

}

/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** entryPoint
*/


#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <memory>

#include "ArcadeSdl.hpp"

extern "C" std::unique_ptr<arcade::IDisplayModule> entryPoint()
{
    return std::make_unique<arcade::ArcadeSdl>();
}

arcade::ArcadeSdl::ArcadeSdl()
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    _window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    setTexturesPath("Assets");
    setKeyMap();
}

arcade::ArcadeSdl::~ArcadeSdl()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

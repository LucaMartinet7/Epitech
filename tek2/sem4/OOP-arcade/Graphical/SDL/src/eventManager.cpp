/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet [WSL: Ubuntu]
** File description:
** eventManager
*/

#include "ArcadeSdl.hpp"
#include "AEvent.hpp"

void arcade::ArcadeSdl::setKeyMap(void)
{
    _keyMap[SDLK_UP] = "Up";
    _keyMap[SDLK_DOWN] = "Down";
    _keyMap[SDLK_LEFT] = "Left";
    _keyMap[SDLK_RIGHT] = "Right";
    _keyMap[SDLK_ESCAPE] = "Escape";
    _keyMap[SDLK_SPACE] = "Space";
    _keyMap[SDLK_RETURN] = "Enter";
    _keyMap[SDLK_l] = "NextL";
    _keyMap[SDLK_g] = "NextG";
    _keyMap[SDLK_r] = "Restart";
    _keyMap[SDLK_m] = "Menu";
    _keyMap[SDLK_q] = "Exit";
}

std::vector<std::unique_ptr<arcade::IEvent>> const &arcade::ArcadeSdl::getEvent(void)
{
    _events.clear();

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_RESIZED)
            SDL_SetWindowSize(_window, event.window.data1, event.window.data2);
        if (event.type == SDL_QUIT)
            _events.push_back(std::make_unique<AEvent>("Exit"));
        if (event.type == SDL_KEYDOWN) {
            auto it = _keyMap.find(event.key.keysym.sym);
            if (it != _keyMap.end())
                _events.push_back(std::make_unique<AEvent>(it->second));
        }
    }
    return _events;
}

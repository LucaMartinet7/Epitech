/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** ArcadeSdl
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <map>

#include "IArcade.hpp"

#ifndef _ARCADESDL_HPP
    #define _ARCADESDL_HPP

#define WINDOW_WIDTH 1900
#define WINDOW_HEIGHT 1000

namespace arcade {
    class ArcadeSdl : public IDisplayModule{
        public:
            ArcadeSdl();
            void display(const data_t& data) override;
            void clear(void) override;
            std::vector<std::unique_ptr<IEvent>> const &getEvent(void) override;

            void setKeyMap(void);
            void setTexturesPath(std::string Path);
            bool textureExist(std::string texturePath);
            ~ArcadeSdl();

        protected:
            std::map<SDL_Keycode, std::string> _keyMap;
            std::vector<std::unique_ptr<IEvent>> _events;
            std::vector<std::string> _texturePath;
            SDL_Renderer *_renderer;
            SDL_Window *_window;
            SDL_Event _event;
    };
}

#endif /* !_ARCADESDL_HPP */

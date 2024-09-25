/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet [WSL: Ubuntu]
** File description:
** screenManager
*/

#include <SDL2/SDL_ttf.h>

#include "ArcadeSdl.hpp"

void arcade::ArcadeSdl::display(const data_t &data)
{
    int windowWidth;
    int windowHeight;
    SDL_GetWindowSize(_window, &windowWidth, &windowHeight);
    int tileSize = 20;
    int startX = (windowWidth - data.size.first * tileSize) / 2;
    int startY = (windowHeight - data.size.second * tileSize) / 2;
    int posX = 0;
    int posY = 0;

    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
    for (auto &obj : data.objects) {
        posX = startX + obj->getPos()[0] * tileSize;
        posY = startY + obj->getPos()[1] * tileSize;
        if (obj->getType() == arcade::Type::Graphic && !obj->getAsset().empty() && obj->getAsset() != "" && textureExist(obj->getAsset())) {
            SDL_Texture* texture = IMG_LoadTexture(_renderer, obj->getAsset().c_str());
            if (texture) {
                SDL_Rect destRect = {posX, posY, obj->getSize()[0] * tileSize, obj->getSize()[1] * tileSize};
                SDL_RenderCopy(_renderer, texture, NULL, &destRect);
                SDL_DestroyTexture(texture);
                continue;
            }
        } else if (obj->getType() == arcade::Type::Text) {
            TTF_Font* font = TTF_OpenFont("Assets/font.ttf", 20);
            if (font) {
                SDL_Color color = {static_cast<Uint8>(obj->getRGB()[0]), static_cast<Uint8>(obj->getRGB()[1]), static_cast<Uint8>(obj->getRGB()[2]), 255};
                SDL_Surface* surface = TTF_RenderText_Solid(font, obj->getAsset().c_str(), color);
                if (surface) {
                    int textWidth = surface->w;
                    int textHeight = surface->h;

                    SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer, surface);
                    if (texture) {
                        SDL_Rect destRect = {posX, posY, textWidth, textHeight};
                        SDL_RenderCopy(_renderer, texture, NULL, &destRect);
                        SDL_DestroyTexture(texture);
                    }
                    SDL_FreeSurface(surface);
                }
                TTF_CloseFont(font);
                continue;
            }
        }
        SDL_Rect rect = {posX, posY, obj->getSize()[0] * tileSize, obj->getSize()[1] * tileSize};
        SDL_SetRenderDrawColor(_renderer, obj->getRGB()[0], obj->getRGB()[1], obj->getRGB()[2], 255);
        SDL_RenderFillRect(_renderer, &rect);
    }
    SDL_RenderPresent(_renderer);
}

void arcade::ArcadeSdl::clear(void)
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
}

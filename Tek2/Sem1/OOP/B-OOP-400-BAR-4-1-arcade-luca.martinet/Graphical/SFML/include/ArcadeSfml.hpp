/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** ArcadeSfml
*/

#include <SFML/Graphics.hpp>
#include <list>
#include <map>
#include <memory>
#include <vector>
#include <deque>

#include "IArcade.hpp"

#ifndef _ARCADESFML_HPP
    #define _ARCADESFML_HPP

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

namespace arcade {
    class ArcadeSfml : public IDisplayModule{
        public:
            ArcadeSfml();
            void display(const data_t& data) override;
            void clear(void) override;
            std::vector<std::unique_ptr<IEvent>> const &getEvent(void) override;

            void setKeyMap(void);
            void setTexturesPath(std::string Path);
            bool textureExist(std::string texturePath);
            ~ArcadeSfml();

        protected:
            std::map<sf::Keyboard::Key, std::string> _keyMap;
            std::vector<std::unique_ptr<IEvent>> _events;
            std::vector<std::string> _texturePath;
            sf::RenderWindow _window;
            sf::Event _event;
    };
}

#endif /* !_ARCADESFML_HPP */

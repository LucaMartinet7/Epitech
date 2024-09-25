/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** screenManager
*/

#include "ArcadeSfml.hpp"

void arcade::ArcadeSfml::display(const data_t &data)
{
    sf::Vector2u windowSize = _window.getSize();
    int tileSize = 20;
    int startX = (windowSize.x - data.size.first * tileSize) / 2;
    int startY = (windowSize.y - data.size.second * tileSize) / 2;
    int posX = 0;
    int posY = 0;

    _window.clear(sf::Color::Black);
    for (auto &obj : data.objects) {
        posX = startX + obj->getPos()[0] * tileSize;
        posY = startY + obj->getPos()[1] * tileSize;
        if (obj->getType() == arcade::Type::Graphic && !obj->getAsset().empty() && obj->getAsset() != "" && textureExist(obj->getAsset())) {
            sf::Texture texture;
            if (texture.loadFromFile(obj->getAsset())) {
                sf::Sprite sprite(texture);
                sprite.setPosition(posX, posY);
                sf::Vector2u textureSize = texture.getSize();
                sf::Vector2f scale(obj->getSize()[0] * tileSize / static_cast<float>(textureSize.x),
                                   obj->getSize()[1] * tileSize / static_cast<float>(textureSize.y));
                sprite.setScale(scale);
                _window.draw(sprite);
                continue;
            }
        } else if (obj->getType() == arcade::Type::Text) {
            sf::Font font;
            if (font.loadFromFile("Assets/font.ttf")) {
                sf::Text text;
                text.setFont(font);
                text.setString(obj->getAsset());
                text.setCharacterSize(tileSize);
                text.setFillColor(sf::Color(obj->getRGB()[0], obj->getRGB()[1], obj->getRGB()[2]));
                text.setPosition(posX, posY);
                _window.draw(text);
                continue;
            }
        }
        sf::RectangleShape rect(sf::Vector2f(obj->getSize()[0] * tileSize, obj->getSize()[1] * tileSize));
        rect.setPosition(posX, posY);
        rect.setFillColor(sf::Color(obj->getRGB()[0], obj->getRGB()[1], obj->getRGB()[2]));
        _window.draw(rect);
    }

    _window.display();
}

void arcade::ArcadeSfml::clear(void)
{
    _window.clear(sf::Color(0, 0, 0));
}

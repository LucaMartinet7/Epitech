/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGRUSH3-jules.dufraiche
** File description:
** SFMLDisplay
*/

#include <sstream>
#include <iostream>

#include "SFMLDisplay.hpp"

namespace Krell
{
    SFMLDisplay::SFMLDisplay() : _window(sf::VideoMode(1920, 1080), "SFMLDisplay"), _rectangles(2, std::vector<sf::RectangleShape>(2))
    {
        if (!_font.loadFromFile("arial.ttf"))
            throw std::runtime_error("Cannot load font");
    }

    SFMLDisplay::~SFMLDisplay()
    {
        _window.close();
    }

    void SFMLDisplay::show(int width)
    {
        const unsigned int wid = _window.getSize().x;
        const unsigned int height = _window.getSize().y;

        const unsigned int numColumns = 2;
        const unsigned int numRows = (_modules.size() + numColumns - 1) / numColumns;

        const float boxWidth = (wid - (numColumns + 1) * 20.f) / numColumns;
        const float boxHeight = (height - (numRows + 1) * 20.f) / numRows;

        while (_window.isOpen())
        {
            for (auto &m : this->_modules)
                m->update();
            sf::Event event;
            while (_window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    _window.close();
                else if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Q)
                    {
                        _window.close();
                    }
                }
            }
            _window.clear(sf::Color(50, 50, 50));
            for (const auto &row : _rectangles)
            {
                for (const auto &rect : row)
                {
                    _window.draw(rect);
                }
            }
            for (size_t i = 0; i < _modules.size(); ++i)
            {
                const unsigned int row = i / numColumns;
                const unsigned int col = i % numColumns;

                const float x = 20.f + col * (boxWidth + 20.f);
                const float y = 20.f + row * (boxHeight + 20.f);

                sf::RectangleShape box = initializeRectangle(sf::Vector2f(boxWidth, boxHeight), x, y);
                _window.draw(box);

                sf::Text titleText = setText(_modules[i]->getName(), x + 5, y + 5);
                _window.draw(titleText);

                sf::Text dataText = setText(_modules[i]->getData().c_str(), x + 5, y + 30);
                _window.draw(dataText);
            }

            _window.display();
            sf::sleep(sf::seconds(1));
        }
    }

    void SFMLDisplay::update(IModule *updatedModule)
    {
        for (auto &module : this->_modules)
        {
            if (module->getName() == updatedModule->getData())
            {
                IModule *tmp = module;
                module = updatedModule;
                delete tmp;
            }
        }
    }
    void SFMLDisplay::setModule(IModule *module)
    {
        for (auto &m : this->_modules)
        {
            if (m == module)
                return;
        }
        this->_modules.push_back(module);
    }

    sf::Text SFMLDisplay::setText(std::string w1, unsigned int x, unsigned int y)
    {
        sf::Text Text;
        Text.setFont(_font);
        Text.setString(w1);
        Text.setCharacterSize(18);
        Text.setFillColor(sf::Color::White);
        Text.setPosition(x, y);
        return Text;
    }

    sf::RectangleShape SFMLDisplay::initializeRectangle(sf::Vector2f size, float x, float y)
    {
        sf::RectangleShape rect;

        rect.setSize(size);
        rect.setFillColor(sf::Color::Black);
        rect.setOutlineColor(sf::Color::White);
        rect.setOutlineThickness(2.f);
        rect.setPosition(x, y);
        return rect;
    }
}

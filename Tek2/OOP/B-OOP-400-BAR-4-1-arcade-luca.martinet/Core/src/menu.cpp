/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** menu
*/

#include <string>

#include "AObject.hpp"
#include "Lib.hpp"

void arcade::Lib::createMenu()
{
    _menu.size = std::make_pair(30, 30);
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            if (i == 0 || i == 29 || j == 0 || j == 29) {
                std::unique_ptr<arcade::AObject> obj = std::make_unique<arcade::AObject>();
                obj->setPos({i, j});
                obj->setSize({1, 1});
                obj->setRGB({255, 255, 255});
                obj->setAscii('#');
                obj->setAsset("Assets/snake/wall.png");
                obj->setType(arcade::Type::Graphic);
                _menu.objects.push_back(std::move(obj));
            }
        }
    }
}

void arcade::Lib::updateMenu()
{
    clearMenu();
    for (int i = 0; i < (int)_displayModuleList.size(); i++) {
        std::unique_ptr<arcade::AObject> obj = std::make_unique<arcade::AObject>();
        obj->setPos({3, (i + 2)});
        obj->setSize({1, 1});
        if (_cursorCol == 0 && _cursorRow == i)
            obj->setRGB({255, 0, 255});
        else
            obj->setRGB({255, 255, 255});
        obj->setAscii(' ');
        obj->setAsset(_displayModuleList[i].c_str());
        obj->setType(arcade::Type::Text);
        _menu.objects.push_back(std::move(obj));
    }
    for (int i = 0; i < (int)_GameModuleList.size(); i++) {

        std::unique_ptr<arcade::AObject> obj = std::make_unique<arcade::AObject>();
        if (_displayModuleList[_selectedDisplay].find("ncurses") != std::string::npos)
            obj->setPos({3, (i + 10)});
        else
            obj->setPos({15, (i + 2)});
        obj->setSize({1, 1});
        if (_cursorCol == 1 && _cursorRow == i)
            obj->setRGB({255, 0, 255});
        else
            obj->setRGB({255, 255, 255});
        obj->setAscii(' ');
        obj->setAsset(_GameModuleList[i].c_str());
        obj->setType(arcade::Type::Text);
        _menu.objects.push_back(std::move(obj));
    }
}

bool arcade::Lib::manageMenuEvent(std::vector<std::unique_ptr<arcade::IEvent>> const& events)
{
    clearMenu();
    for (auto &event : events) {
        if (event->type() == "Enter") {
            if (_cursorCol == 0) {
                if (_displayModuleActive != nullptr)
                    _displayModuleActive.reset();
                loadModule(_displayModuleList[_cursorRow], libType::Graphic);
                _selectedDisplay = _cursorRow;
                return true;
            }
            if (_gameModuleActive != nullptr)
                _gameModuleActive.reset();
            loadModule(_GameModuleList[_cursorRow], libType::Game);
            _selectedGame = _cursorRow;
            return false;
        } else if (event->type() == "Up") {
            if (_cursorRow > 0)
                _cursorRow--;
        } else if (event->type() == "Down") {
            if ((_cursorCol == 0 && _cursorRow < (int)_displayModuleList.size() - 1) || (_cursorCol == 1 && _cursorRow < (int)_GameModuleList.size() - 1))
                _cursorRow++;
        } else if (event->type() == "Right") {
            if (_cursorCol < 1 && _cursorRow <= (int)_GameModuleList.size() - 1)
                _cursorCol++;
        } else if (event->type() == "Left") {
            if (_cursorCol > 0 && _cursorRow <= (int)_displayModuleList.size() - 1)
                _cursorCol--;
        }
    }
    return true;
}

void arcade::Lib::clearMenu()
{
    _menu.objects.clear();
    createMenu();
}

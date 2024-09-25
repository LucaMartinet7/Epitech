/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** core
*/

#include <iostream>
#include <dlfcn.h>

#include "Core.hpp"

arcade::Core::Core()
{
    _selectedDisplayModule = nullptr;
    _selectedGameModule = nullptr;
}

void arcade::Core::init(char *libPath)
{
    lib.findDisplayLib();
    lib.findGamesLib();
    lib.selectFirstLib(libPath);
    lib.loadModule(libPath, libType::Graphic);
    lib.createMenu();
    _isMenu = true;
}

bool arcade::Core::eventManager(std::vector<std::unique_ptr<arcade::IEvent>> const& events)
{
    for (auto &event : events) {
        if (event->type() == "Exit") {
            return true;
        } else if (event->type() == "Menu") {
            _isMenu = true;
        } else if (event->type() == "NextL") {
            lib.loadNextModule(libType::Graphic);
        } else if (event->type() == "NextG") {
            lib.loadNextModule(libType::Game);
        }
    }
    return false;
}

void arcade::Core::loop(void)
{
    while (1) {
        std::vector<std::unique_ptr<arcade::IEvent>> const& events = lib._displayModuleActive->getEvent();
        if (eventManager(events))
            break;
        if (_isMenu) {
            lib._displayModuleActive->clear();
            lib._displayModuleActive->display(lib._menu);
            _isMenu = lib.manageMenuEvent(events);
            lib.updateMenu();
            continue;
        }
        lib._displayModuleActive->clear();
        lib._displayModuleActive->display(lib._gameModuleActive->getMap());
        lib._gameModuleActive->manageEvent(events);
        lib._gameModuleActive->iterate();
    }
    lib._displayModuleActive.reset();
    lib._gameModuleActive.reset();
}

arcade::Core::~Core()
{
    return;
}
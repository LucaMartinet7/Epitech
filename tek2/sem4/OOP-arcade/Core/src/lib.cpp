/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** Lib
*/

#include <iostream>
#include <unistd.h>
#include <dirent.h>
#include <dlfcn.h>
#include <memory>

#include "Lib.hpp"

arcade::Lib::Lib()
{
    _selectedDisplay = 0;
    _selectedGame = 0;
    _dispHandle = nullptr;
    _gameHandle = nullptr;
    _cursorCol = 0;
    _cursorRow = 0;
}

void arcade::Lib::findDisplayLib(void)
{
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir ("./lib/")) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            if (is_display_lib(ent->d_name))
                setModule(ent->d_name, libType::Graphic);
        }
        closedir(dir);
    } else {
        perror("");
        exit(84);
    }
}

void arcade::Lib::findGamesLib(void)
{
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir ("./lib/")) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            if (is_game_lib(ent->d_name))
                setModule(ent->d_name, libType::Game);
        }
        closedir(dir);
    } else {
        perror("");
        exit(84);
    }
}

void arcade::Lib::setModule(std::string libName, libType mode)
{
    std::string Path = "./lib/" + libName;

    if (mode == libType::Graphic) {
        _displayModuleList.push_back(libName);
    } else {
        _GameModuleList.push_back(libName);
    }
}

void arcade::Lib::loadModule(std::string libName, libType mode)
{
    std::string Path = "./lib/" + libName.substr(libName.find_last_of('/') + 1);
    void *libHandle = dlopen(Path.c_str(), RTLD_LAZY | RTLD_GLOBAL);
    if (!libHandle) {
        std::cerr << "Error when loading lib : " << libName << " : " << dlerror() << std::endl;
        exit(84);
    }
    if (mode == libType::Graphic) {
        std::unique_ptr<arcade::IDisplayModule> (*entryLibPoint)() = (std::unique_ptr<arcade::IDisplayModule> (*)())dlsym(libHandle, "entryPoint");
        if (!entryLibPoint) {
            std::cerr << "Error when getting symbol : " << dlerror() << " in (display lib) : " << libName << std::endl;
            exit(84);
        }
        if (_displayModuleActive != NULL)
            dlclose(_dispHandle);
        if (_displayModuleActive != NULL)
            _displayModuleActive.reset();
        _dispHandle = libHandle;
        _displayModuleActive = entryLibPoint();
    } else {
        std::unique_ptr<arcade::IGameModule> (*entryLibPoint)() = (std::unique_ptr<arcade::IGameModule> (*)())dlsym(libHandle, "entryPoint");
        if (!entryLibPoint) {
            std::cerr << "Error when getting symbol : " << dlerror() << " in (game lib) : " << libName << std::endl;
            exit(84);
        }
        if (_gameModuleActive != NULL)
            dlclose(_gameHandle);
        if (_gameModuleActive != NULL)
            _gameModuleActive.reset();
        _gameHandle = libHandle;
        _gameModuleActive = entryLibPoint();
    }
}

void arcade::Lib::loadNextModule(libType mode)
{
    if (mode == libType::Graphic) {
        if (_selectedDisplay + 1 >= (int)_displayModuleList.size())
            _selectedDisplay = 0;
        else
            _selectedDisplay++;
        if (_selectedDisplay < (int)_displayModuleList.size()) {
            _displayModuleActive.reset();
            loadModule(_displayModuleList[_selectedDisplay], mode);
        }
    } else {
        if (_selectedGame + 1 >= (int)_GameModuleList.size())
            _selectedGame = 0;
        else
            _selectedGame++;
        if (_selectedGame < (int)_GameModuleList.size()) {
            if (_gameModuleActive != nullptr)
                _gameModuleActive.reset();
            loadModule(_GameModuleList[_selectedGame], mode);
        }
    }
}

void arcade::Lib::selectFirstLib(std::string libName)
{
    std::string name = libName.substr(libName.find_last_of('/') + 1);;

    for (size_t i = 0; i < _displayModuleList.size(); i++) {
        if (_displayModuleList[i] == name) {
            _selectedDisplay = i;
            break;
        }
    }
}

arcade::Lib::~Lib()
{
    return;
}

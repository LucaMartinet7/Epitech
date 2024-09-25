/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** textureManager
*/

#include <iostream>
#include <dirent.h>

#include "ArcadeSdl.hpp"

void arcade::ArcadeSdl::setTexturesPath(std::string Path)
{
    DIR* directory = opendir(Path.c_str());
    if (directory == nullptr) {
        std::cerr << "Erreur lors de l'ouverture du dossier " << Path << std::endl;
        return;
    }

    dirent* entry;
    while ((entry = readdir(directory)) != nullptr) {
        if (entry->d_type == DT_DIR) {
            if (std::string(entry->d_name) != "." && std::string(entry->d_name) != "..") {
                std::string sousDossier = Path + "/" + entry->d_name;
                setTexturesPath(sousDossier);
            }
        } else if (entry->d_type == DT_REG) {
            _texturePath.push_back(Path + "/" + entry->d_name);
        }
    }

    closedir(directory);
}

bool arcade::ArcadeSdl::textureExist(std::string texturePath)
{
    for (auto &path : _texturePath) {
        if (path == texturePath)
            return true;
    }
    return false;
}

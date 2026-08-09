/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD11-luca.martinet
** File description:
** DirectoryLister
*/

#include "DirectoryLister.hpp"

DirectoryLister::DirectoryLister(const std::string &path, bool hidden) : hidden(hidden)
{
    open(path, hidden);
}

DirectoryLister::~DirectoryLister()
{
    if (dir != nullptr)
        closedir(dir);
}

bool DirectoryLister::open(const std::string &path, bool _hidden)
{
    hidden = _hidden;

    if (dir != nullptr)
        closedir(dir);

    dir = opendir(path.data());

    if (dir == nullptr) {
        perror(path.data());
        return false;
    }
    return true;
}

std::string DirectoryLister::get()
{
    if (dir == nullptr)
        return "";

    struct dirent *current = readdir(dir);

    if (current == nullptr)
        return "";
    if (!hidden && current->d_name[0] == '.')
        return get();
    return current->d_name;
}

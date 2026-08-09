/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD11-luca.martinet
** File description:
** SafeDirectoryLister
*/

#include "SafeDirectoryLister.hpp"
#include <iostream>

SafeDirectoryLister::SafeDirectoryLister(const std::string &path, bool hidden) : hidden(hidden)
{
    open(path, hidden);
}

SafeDirectoryLister::~SafeDirectoryLister()
{
    if (dir != nullptr)
        closedir(dir);
}

bool SafeDirectoryLister::open(const std::string &path, bool _hidden)
{
    hidden = _hidden;

    if (dir != nullptr)
        closedir(dir);

    dir = opendir(path.data());

    if (dir == nullptr) {
        throw OpenFailureException();
    }
    return true;
}

std::string SafeDirectoryLister::get()
{
    if (dir == nullptr)
        throw OpenFailureException();

    struct dirent *current = readdir(dir);

    if (current == nullptr)
        throw NoMoreFileException();
    if (!hidden && current->d_name[0] == '.')
        return get();
    return current->d_name;
}

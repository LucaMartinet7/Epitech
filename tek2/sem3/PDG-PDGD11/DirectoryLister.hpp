/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD11-luca.martinet
** File description:
** DirectoryLister
*/

#ifndef DIRECTORYLISTER_HPP_
    #define DIRECTORYLISTER_HPP_

#include "IDirectoryLister.hpp"
#include <string>
#include <dirent.h>

class DirectoryLister : public IDirectoryLister {
    public:
        DirectoryLister() = default;
        ~DirectoryLister();
        DirectoryLister(const std::string &path, bool hidden);

        bool open(const std::string &path, bool hidden) override;
        std::string get() override;

    private:
        bool hidden = false;
        DIR *dir = nullptr;
};

#endif /* !DIRECTORYLISTER_HPP_ */

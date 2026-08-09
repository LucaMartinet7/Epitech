/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD11-luca.martinet
** File description:
** SafeDirectoryLister
*/

#ifndef SAFEDIRECTORYLISTER_HPP_
    #define SAFEDIRECTORYLISTER_HPP_

#include "IDirectoryLister.hpp"
#include <string>
#include <dirent.h>

class SafeDirectoryLister : public IDirectoryLister {
    public:
        SafeDirectoryLister() = default;
        ~SafeDirectoryLister();
        SafeDirectoryLister(const std::string &path, bool hidden);

        bool open(const std::string &path, bool hidden) override;
        std::string get() override;

    private:
        bool hidden = false;
        DIR *dir = nullptr;
};

#endif /* !SAFEDIRECTORYLISTER_HPP_ */

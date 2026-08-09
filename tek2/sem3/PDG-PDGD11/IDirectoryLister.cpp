/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD11-luca.martinet
** File description:
** IDirectoryLister
*/

#include "IDirectoryLister.hpp"
#include <cstring>
#include <cerrno>


const char *IDirectoryLister::OpenFailureException::what() const noexcept
{
    return strerror(errno);
}

const char *IDirectoryLister::NoMoreFileException::what() const noexcept
{
    return "End of stream";
}

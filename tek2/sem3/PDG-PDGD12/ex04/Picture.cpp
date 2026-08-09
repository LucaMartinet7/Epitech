/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD12-luca.martinet
** File description:
** Picture
*/

#include "Picture.hpp"
#include <fstream>

bool Picture::getPictureFromFile(const std::string &file)
{
    std::ifstream ifs(file);
    std::string line;

    if (!ifs.is_open()) {
        this->data = "ERROR";
        return false;
    }
    this->data = "";
    while (getline(ifs, line)) {
        this->data += line + "\n";
        if (ifs.eof())
            this->data += "\n";
    }
    return true;
}

Picture::Picture(const std::string &file)
{
    this->getPictureFromFile(file);
}



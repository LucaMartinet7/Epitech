/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD12-luca.martinet
** File description:
** Picture
*/

#ifndef PICTURE_HPP_
    #define PICTURE_HPP_

#include <string>

class Picture {
    public:
        std::string data;

        Picture(const std::string &file);
        Picture() = default;

        bool getPictureFromFile(const std::string &file);
};

#endif /* !PICTURE_HPP_ */

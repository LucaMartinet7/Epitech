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

    Picture() = default;
    Picture(const Picture &other) = default;
    Picture& operator=(const Picture& other) = default;
    ~Picture() = default;
    explicit Picture(const std::string& file);

    bool getPictureFromFile(const std::string& file);
};

#endif /* !PICTURE_HPP_ */

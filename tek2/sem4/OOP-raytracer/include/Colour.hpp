/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-raytracer-jules.dufraiche
** File description:
** RGB
*/

#ifndef COLOUR_HPP_
#define COLOUR_HPP_

class Colour {
    public:
        Colour();
        Colour(float r, float g, float b);
        Colour AddColour();

        float _red;
        float _green;
        float _blue;
};

#endif /* !COLOUR_HPP_ */

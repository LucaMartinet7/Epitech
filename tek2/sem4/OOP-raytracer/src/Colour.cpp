/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-raytracer-jules.dufraiche
** File description:
** Colour
*/

#include <algorithm>

#include "Colour.hpp"

Colour::Colour() : _red(0.0), _green(0.0), _blue(0.0) {}

Colour::Colour(float r, float g, float b) : _red(r), _green(g), _blue(b) {}

Colour Colour::AddColour()
{
    float max = std::max(_red, std::max(_green, _blue));
    return Colour(_red / max, _green / max, _blue / max);
}

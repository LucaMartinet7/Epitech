/*
** EPITECH PROJECT, 2024
** R-type ECS
** File description:
** Draw System
*/

#ifndef DRAWSYSTEM_H
    #define DRAWSYSTEM_H

#include "Registry.hpp"
#include "Position.hpp"
#include "Drawable.hpp"
#include <SFML/Graphics.hpp>

inline void draw_system(Registry& registry, sf::RenderWindow& window, sparse_array<Position>& positions, sparse_array<Drawable>& drawables) {
    for (size_t i = 0; i < positions.size() && i < drawables.size(); ++i) {
        auto& pos = positions[i];
        auto& drawable = drawables[i];
        if (pos && drawable) {
            drawable->shape.setPosition(pos->x, pos->y);
            window.draw(drawable->shape);
        }
    }
}

#endif // DRAWSYSTEM_H

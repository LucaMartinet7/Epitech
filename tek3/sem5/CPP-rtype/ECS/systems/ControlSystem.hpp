/*
** EPITECH PROJECT, 2024
** R-Type ECS
** File description:
** Control System
*/

#ifndef CONTROLSYSTEM_H
    #define CONTROLSYSTEM_H

#include "Registry.hpp"
#include "Velocity.hpp"
#include "Controllable.hpp"
#include <SFML/Window.hpp>
#include "CollisionSystem.hpp"

inline void control_system(Registry& registry, sparse_array<Velocity>& velocities, sparse_array<Controllable>& controllables, sparse_array<Position>& positions, sparse_array<Drawable>& drawables, sparse_array<Collidable>& collidables) {
    for (size_t i = 0; i < velocities.size() && i < controllables.size(); ++i) {
        auto& vel = velocities[i];
        auto& ctrl = controllables[i];
        if (vel && ctrl) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                vel->vx = -0.125f;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                vel->vx = 0.125f;
            } else {
                vel->vx = 0.0f;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                vel->vy = -0.125f;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                vel->vy = 0.125f;
            } else {
                vel->vy = 0.0f;
            }
        }
    }
}

#endif // CONTROLSYSTEM_H

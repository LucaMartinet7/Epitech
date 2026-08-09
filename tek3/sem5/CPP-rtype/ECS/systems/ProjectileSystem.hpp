/*
** EPITECH PROJECT, 2024
** R-Type ECS
** File description:
** ProjectileSystem
*/

#ifndef PROJECTILESYSTEM_H
    #define PROJECTILESYSTEM_H

#include "Registry.hpp"
#include "Position.hpp"
#include "Projectile.hpp"
#include "Drawable.hpp"
#include "Collidable.hpp"
#include "Velocity.hpp"
#include <iostream>

inline void projectile_system(Registry& registry, sparse_array<Position>& positions, sparse_array<Velocity>& velocities, sparse_array<Projectile>& projectiles, sparse_array<Drawable>& drawables, sparse_array<Collidable>& collidables) {
    for (size_t i = 0; i < positions.size() && i < velocities.size() && i < projectiles.size() && i < drawables.size() && i < collidables.size(); ++i) {
        auto& pos = positions[i];
        auto& vel = velocities[i];
        auto& proj = projectiles[i];
        auto& drawable = drawables[i];
        auto& collidable = collidables[i];
        if (pos && vel && proj && drawable && collidable) {
            pos->x += vel->vx * proj->speed;
            pos->y += vel->vy * proj->speed;
            std::cout << "Projectile " << i << " position: (" << pos->x << ", " << pos->y << ")" << std::endl;
            if (pos->x > 800) {
                std::cout << "Killing entity " << i << std::endl;
                registry.kill_entity(i);
                continue;
            }
            for (size_t j = 0; j < positions.size() && j < drawables.size() && j < collidables.size(); ++j) {
                if (i == j) continue;
                auto& otherPos = positions[j];
                auto& otherDrawable = drawables[j];
                auto& otherCollidable = collidables[j];
                if (otherPos && otherDrawable && otherCollidable && otherCollidable->is_collidable) {
                    if (drawable->shape.getGlobalBounds().intersects(otherDrawable->shape.getGlobalBounds())) {
                        std::cout << "Collision detected between " << i << " and " << j << std::endl;
                        registry.kill_entity(i);
                        registry.kill_entity(j);
                        break;
                    }
                }
            }
        }
    }
}

#endif // PROJECTILESYSTEM_H
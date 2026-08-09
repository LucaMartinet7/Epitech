#ifndef COLLISIONSYSTEM_H
    #define COLLISIONSYSTEM_H

#include "Registry.hpp"
#include "Position.hpp"
#include "Collidable.hpp"
#include "Drawable.hpp"
#include "Projectile.hpp"
#include "Controllable.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

inline bool check_collision(const sf::RectangleShape& shape1, const sf::RectangleShape& shape2) {
    return shape1.getGlobalBounds().intersects(shape2.getGlobalBounds());
}

inline std::vector<std::pair<size_t, size_t>> collision_system(Registry& registry, sparse_array<Position>& positions, sparse_array<Drawable>& drawables, sparse_array<Collidable>& collidables, sparse_array<Controllable>& controllables, sparse_array<Projectile>& projectiles) {
    std::vector<std::pair<size_t, size_t>> collisions;
    for (size_t i = 0; i < positions.size() && i < drawables.size() && i < collidables.size(); ++i) {
        auto& pos = positions[i];
        auto& drawable = drawables[i];
        auto& collidable = collidables[i];
        if (pos && drawable && collidable && collidable->is_collidable) {
            for (size_t j = i + 1; j < positions.size() && j < drawables.size() && j < collidables.size(); ++j) {
                auto& otherPos = positions[j];
                auto& otherDrawable = drawables[j];
                auto& otherCollidable = collidables[j];
                if (otherPos && otherDrawable && otherCollidable && otherCollidable->is_collidable) {
                    if (check_collision(drawable->shape, otherDrawable->shape)) {
                        collisions.emplace_back(i, j); // Record collision
                        if (controllables[i] || controllables[j]) {
                            registry.kill_entity(controllables[i] ? i : j);
                        }
                        if (projectiles[i] || projectiles[j]) {
                            registry.kill_entity(projectiles[i] ? j : i);
                            registry.kill_entity(projectiles[i] ? i : j);
                        } else {
                            if (!controllables[i] && !controllables[j]) {
                                registry.kill_entity(i);
                                registry.kill_entity(j);
                            }
                        }
                    }
                }
            }
        }
    }
    return collisions; // Return list of collisions
}

#endif // COLLISIONSYSTEM_H
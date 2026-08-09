/*
** EPITECH PROJECT, 2025
** R-Type [WSL: Ubuntu]
** File description:
** Boss
*/

#include "Boss.hpp"
#include "Position.hpp"
#include "Velocity.hpp"
#include "Drawable.hpp"
#include "Collidable.hpp"
#include <iostream>

Boss::Boss(Registry registry, float x, float y) : registry(registry) {
    entity = this->registry.spawn_entity();
    this->registry.add_component<Position>(entity, {x, y});
    this->registry.add_component<Velocity>(entity, {0.0f, 0.0f});
    this->registry.add_component<Drawable>(entity, {sf::RectangleShape(sf::Vector2f(100.0f, 100.0f))});
    this->registry.add_component<Collidable>(entity, {true});
}

Boss::~Boss() {
    if (registry.entity_exists(entity))
        registry.kill_entity(entity);
}

void Boss::move(float x, float y) {
    if (registry.has_component<Position>(entity)) {
        auto& pos = registry.get_components<Position>()[entity];
        pos->x += x;
        pos->y += y;
    } else {
        std::cerr << "Error: Boss entity does not have a Position component." << std::endl;
    }
}

Registry::Entity Boss::getEntity() const {
    return entity;
}

const Registry& Boss::getRegistry() const {
    return registry;
}

void Boss::setRegistry(const Registry& newRegistry) {
    registry = newRegistry;
}

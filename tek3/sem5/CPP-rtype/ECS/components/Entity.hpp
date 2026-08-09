/*
** EPITECH PROJECT, 2024
** R-Type ECS
** File description:
** Entity
*/

#ifndef ENTITY_H
  #define ENTITY_H

#include <cstddef>

class Entity {
  public:
    explicit Entity(std::size_t id) : id(id) {}
    operator std::size_t() const { return id; }
  private:
    std::size_t id;
};

#endif //ENTITY_H

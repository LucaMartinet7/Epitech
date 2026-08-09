#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Registry.hpp"

class Enemy {
public:
    Enemy(Registry registry, float x, float y);
    ~Enemy();

    void move(float x, float y);
    Registry::Entity getEntity() const;

    const Registry& getRegistry() const;
    void setRegistry(const Registry& newRegistry);

private:
    Registry registry;
    Registry::Entity entity;
};

#endif // ENEMY_HPP
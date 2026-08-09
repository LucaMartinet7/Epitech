#ifndef BULLET_HPP
#define BULLET_HPP

#include "Registry.hpp"

class Bullet {
public:
    Bullet(Registry registry, float x, float y, float speed);
    ~Bullet();

    void move(float x, float y);
    Registry::Entity getEntity() const;

    const Registry& getRegistry() const; 
    void setRegistry(const Registry& newRegistry);

private:
    Registry registry;
    Registry::Entity entity;
};

#endif // BULLET_HPP
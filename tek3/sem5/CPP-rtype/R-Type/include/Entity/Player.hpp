#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Registry.hpp"

class Player {
public:
    Player(Registry registry, float x, float y);
    ~Player();

    void move(float x, float y);
    Registry::Entity getEntity() const;

    const Registry& getRegistry() const;
    void setRegistry(const Registry& newRegistry);

private:
    Registry registry;
    Registry::Entity entity;
};

#endif // PLAYER_HPP
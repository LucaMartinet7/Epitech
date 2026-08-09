#ifndef BOSS_HPP
    #define BOSS_HPP

#include "Registry.hpp"

class Boss {
public:
    Boss(Registry registry, float x, float y);
    ~Boss();

    void move(float x, float y);
    Registry::Entity getEntity() const;

    const Registry& getRegistry() const;
    void setRegistry(const Registry& newRegistry);

private:
    Registry registry;
    Registry::Entity entity;
};

#endif //BOSS_HPP

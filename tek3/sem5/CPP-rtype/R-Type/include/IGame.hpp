/*
** EPITECH PROJECT, 2025
** R-Type [WSL: Ubuntu]
** File description:
** IGame
*/

#ifndef IGAME_HPP
#define IGAME_HPP

#include <vector>
#include <utility>
#include <cstddef>
#include "PlayerAction.hpp"

class IGame {
public:
    virtual ~IGame() = default;

    // Pure virtual functions to be implemented by noe in GameState class
    virtual void update() = 0;
    virtual void handlePlayerMove(int playerId, int actionId) = 0;
    virtual void killPlayers(int entityId) = 0;
    virtual void killEnemies(int entityId) = 0;
    virtual void killBullets(int entityId) = 0;
    virtual void killBosses(int entityId) = 0;
    virtual void killEntity(int entityId) = 0;
    virtual void spawnPlayer(int playerId, float x, float y) = 0;
    virtual void spawnEnemy(int enemyId, float x, float y) = 0;
    virtual void spawnBullet(int playerId) = 0;
    virtual void spawnBoss(int bossId, float x, float y) = 0;
    virtual size_t getPlayerCount() const = 0;
    virtual size_t getEnemiesCount() const = 0;
    virtual size_t getBulletsCount() const = 0;
    virtual size_t getBossCount() const = 0;
    virtual std::pair<float, float> getPlayerPosition(int playerId) const = 0;
    virtual std::pair<float, float> getBulletPosition(int bulletId) const = 0;
    virtual std::pair<float, float> getEnemyPosition(int enemyId) const = 0;
    virtual std::pair<float, float> getBossPosition(int enemyId) const = 0;

    // Functions for managing player actions
    virtual void addPlayerAction(int playerId, int actionId) = 0;
    virtual void processPlayerActions() = 0;
    virtual void deletePlayerAction() = 0;
    virtual const std::vector<PlayerAction>& getPlayerActions() const = 0;
};

#endif // IGAME_HPP

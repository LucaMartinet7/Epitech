#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "AGame.hpp"
#include "Registry.hpp"
#include <random>
#include <memory> 
#include <chrono>

class GameState : public AGame {
public:
    GameState(RType::Server* server);

    void initializeplayers(int numPlayers);
    void update() override;
    void handlePlayerMove(int playerId, int actionId) override;
    bool isBossSpawned() const;
    bool areEnemiesCleared() const;
    void startNextWave();
    void run(int numPlayers);

    int currentWave;

    size_t getPlayerCount() const override;
    size_t getEnemiesCount() const override;
    size_t getBulletsCount() const override;
    size_t getBossCount() const override;

private:
    std::mt19937 rng;
    std::uniform_real_distribution<float> distX;
    std::uniform_real_distribution<float> distY;
    std::uniform_int_distribution<int> distTime;
    int enemiesPerWave;
    std::chrono::steady_clock::time_point lastSpawnTime; 

    void checkAndKillEntities(Registry::Entity entity1, Registry::Entity entity2);
    const Registry& getEntityRegistry(Registry::Entity entity);
    void checkCollisions();
    void spawnEnemiesRandomly();
    RType::Server* m_server; // Pointer to RType::Server
    int nextEnemyId;
    int nextBossId;
};

#endif // GAME_STATE_HPP
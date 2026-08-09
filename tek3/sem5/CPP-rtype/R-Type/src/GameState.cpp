#include "Server.hpp"
#include "GameState.hpp"
#include "AGame.hpp"
#include "CollisionSystem.hpp"
#include <algorithm>
#include <iostream>
#include <thread>

GameState::GameState(RType::Server* server)
    : AGame(server), rng(std::random_device()()), distX(0.0f, 800.0f), distY(0.0f, 600.0f),
      distTime(1000, 5000), currentWave(0), enemiesPerWave(5), m_server(server), nextEnemyId(0), nextBossId(0) {}

void GameState::initializeplayers(int numPlayers) {
    for (int i = 0; i < numPlayers; ++i) {
        spawnPlayer(i, 100.0f * (i + 1.0f), 100.0f);
    }
}

void GameState::update() {
    registry.run_systems();
    processPlayerActions();
}

void GameState::run(int numPlayers) {
    initializeplayers(numPlayers);
    while (true) {
        // Update game state
        update();

         //Check if all enemies are cleared and start the next wave or spawn the boss
        if (areEnemiesCleared()) {
             if (isBossSpawned()) {
                 std::cout << "Boss defeated! Game over." << std::endl;
                 break;
             } else if (currentWave >= 3) {
                 spawnBoss(nextBossId++, 400.0f, 300.0f); // Spawn boss at the center of the screen
             } else {
                 startNextWave();
             }
        } else {
            spawnEnemiesRandomly();
        }

        //Sleep for a short duration to simulate frame time
        //std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
}

void GameState::handlePlayerMove(int playerId, int actionId) {
    float moveDistance = 1.0f;
    float x = 0.0f;
    float y = 0.0f;

    if (actionId == 1) { // Left
        x = -moveDistance;
    } else if (actionId == 2) { // Right
        x = moveDistance;
    } else if (actionId == 3) { // Up
        y = -moveDistance;
    } else if (actionId == 4) { // Down
        y = moveDistance;
    }
    players[playerId].move(x, y);
}

bool GameState::isBossSpawned() const {
    return !bosses.empty();
}

bool GameState::areEnemiesCleared() const {
    return enemies.empty();
}

void GameState::startNextWave() {
    currentWave++;
    enemiesPerWave += 5; // Increase the number of enemies per wave
    for (int i = 0; i < enemiesPerWave; ++i) {
        spawnEnemy(i, distX(rng), distY(rng));
    }
}

const Registry& GameState::getEntityRegistry(Registry::Entity entity) { // Check entity type and get the corresponding registry
    auto playerIt = std::find_if(players.begin(), players.end(), [entity](const auto& p) { return p.getEntity() == entity; });
    if (playerIt != players.end()) return playerIt->getRegistry();

    auto enemyIt = std::find_if(enemies.begin(), enemies.end(), [entity](const auto& e) { return e.getEntity() == entity; });
    if (enemyIt != enemies.end()) return enemyIt->getRegistry();

    auto bulletIt = std::find_if(bullets.begin(), bullets.end(), [entity](const auto& b) { return b.getEntity() == entity; });
    if (bulletIt != bullets.end()) return bulletIt->getRegistry();

    auto bossIt = std::find_if(bosses.begin(), bosses.end(), [entity](const auto& b) { return b.getEntity() == entity; });
    if (bossIt != bosses.end()) return bossIt->getRegistry();

    std::cerr << "Error: Entity not found in any registry.";
    throw std::runtime_error("Entity not found in any registry."); //avoid compilation warning even though it will never be reached
}

void GameState::checkAndKillEntities(Registry::Entity entity1, Registry::Entity entity2) { //New collision function to replace the one right under
    // Get registries for both entities using the function above
    const Registry& registry1 = getEntityRegistry(entity1);
    const Registry& registry2 = getEntityRegistry(entity2);

    if (registry1.has_component<Position>(entity1) && registry2.has_component<Position>(entity2)) {
        const auto& pos1 = registry1.get_components<Position>()[entity1];
        const auto& pos2 = registry2.get_components<Position>()[entity2];

        float distance = std::sqrt(std::pow(pos2->x - pos1->x, 2) + std::pow(pos2->y - pos1->y, 2));
        float collisionThreshold = 30.0f;

        if (distance < collisionThreshold) {
            killEntity(entity1);
            killEntity(entity2);
        }
    }
}


void GameState::checkCollisions() {
    for (const auto& [entity1, entity2] : collision_system(
        registry,
        registry.get_components<Position>(),
        registry.get_components<Drawable>(),
        registry.get_components<Collidable>(),
        registry.get_components<Controllable>(),
        registry.get_components<Projectile>()
    )) {
        bool isProjectile1 = registry.has_component<Projectile>(entity1);
        bool isProjectile2 = registry.has_component<Projectile>(entity2);
        bool isPlayer1 = registry.has_component<Controllable>(entity1);
        bool isPlayer2 = registry.has_component<Controllable>(entity2);
        bool isEnemy1 = std::find_if(enemies.begin(), enemies.end(),
            [entity1](auto& e){ return e.getEntity() == entity1; }) != enemies.end();
        bool isEnemy2 = std::find_if(enemies.begin(), enemies.end(),
            [entity2](auto& e){ return e.getEntity() == entity2; }) != enemies.end();

        // Projectile <-> Enemy
        if (isProjectile1 && isEnemy2) {
            registry.kill_entity(entity1);
            registry.kill_entity(entity2);
        } else if (isProjectile2 && isEnemy1) {
            registry.kill_entity(entity1);
            registry.kill_entity(entity2);
        }

        // Player <-> Enemy
        if (isPlayer1 && isEnemy2) {
            registry.kill_entity(entity1);
        } else if (isPlayer2 && isEnemy1) {
            registry.kill_entity(entity2);
        }
    }
}

void GameState::spawnEnemiesRandomly() {
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastSpawnTime).count();

    if (elapsed > distTime(rng) && enemies.size() < 10) {
        float x = distX(rng);
        float y = distY(rng);
        spawnEnemy(nextEnemyId++, x, y);
        lastSpawnTime = now;
    }
}

size_t GameState::getPlayerCount() const {
    return players.size();
}

size_t GameState::getEnemiesCount() const {
    return enemies.size();
}

size_t GameState::getBulletsCount() const {
    return bullets.size();
}

size_t GameState::getBossCount() const {
    return bosses.size();
}

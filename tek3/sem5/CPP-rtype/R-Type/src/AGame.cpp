/*
** EPITECH PROJECT, 2025
** R-Type [WSL: Ubuntu]
** File description:
** AGame
*/

#include "GameState.hpp"
#include "Packet.hpp"
#include "PacketType.hpp"
#include "Server.hpp"
#include "AGame.hpp"
#include <algorithm>
#include <iostream>

AGame::AGame(RType::Server* server) : m_server(server)
{
    registerComponents();
}

AGame::~AGame()
{
    playerActions.clear();
    players.clear();
    enemies.clear();
    bullets.clear();
}

void AGame::registerComponents()
{
    registry.register_component<Position>();
    registry.register_component<Velocity>();
    registry.register_component<Drawable>();
    registry.register_component<Controllable>();
    registry.register_component<Collidable>();
    registry.register_component<Projectile>();
}

void AGame::addPlayerAction(int playerId, int actionId) {
    std::cout << "Player " << playerId << " performed action " << actionId << std::endl;
    std::lock_guard<std::mutex> lock(playerActionsMutex);
    playerActions.emplace_back(playerId, actionId);
}

void AGame::processPlayerActions() {
    for (auto& action : playerActions) {
        int playerId = action.getId();
        int actionId = action.getActionId();

        if (actionId > 0 && actionId < 5) { // Change by real action ID defined in server
            handlePlayerMove(playerId, actionId);
            action.setProcessed(true);
            m_server->playerPacketFactory();
        } else if (actionId == 5) { // Change by real action ID defined in server
            spawnBullet(playerId);
            action.setProcessed(true);
            m_server->bulletPacketFactory();
        }
        // Handle other actions or ignore unknown action IDs
    }
    std::lock_guard<std::mutex> lock(playerActionsMutex);
    deletePlayerAction();
}

void AGame::deletePlayerAction() { //deletes all process elements from the vector of player actions and resizes vector
    playerActions.erase(
        std::remove_if(playerActions.begin(), playerActions.end(),
            [](const PlayerAction& action) { return action.getProcessed(); }),
        playerActions.end());
}

const std::vector<PlayerAction>& AGame::getPlayerActions() const {
    return playerActions;
}

std::pair<float, float> AGame::getPlayerPosition(int playerId) const {
    if (playerId < 0 || playerId >= players.size()) {
        throw std::out_of_range("Invalid player ID");
    }

    const auto& positionComponent = players[playerId].getRegistry().get_components<Position>()[players[playerId].getEntity()];
    return {positionComponent->x, positionComponent->y};
}

std::pair<float, float> AGame::getEnemyPosition(int enemyId) const {
    if (enemyId < 0 || enemyId >= enemies.size()) {
        throw std::out_of_range("Invalid enemy ID");
    }

    const auto& positionComponent = enemies[enemyId].getRegistry().get_components<Position>()[enemies[enemyId].getEntity()];
    return {positionComponent->x, positionComponent->y};
}

std::pair<float, float> AGame::getBulletPosition(int bulletId) const {
    if (bulletId < 0 || bulletId >= bullets.size()) {
        throw std::out_of_range("Invalid bullet ID");
    }

    const auto& positionComponent = bullets[bulletId].getRegistry().get_components<Position>()[bullets[bulletId].getEntity()];
    return {positionComponent->x, positionComponent->y};
}

std::pair<float, float> AGame::getBossPosition(int bossId) const {
    if (bossId < 0 || bossId >= bosses.size()) {
        throw std::out_of_range("Invalid boss ID");
    }

    const auto& positionComponent = bosses[bossId].getRegistry().get_components<Position>()[bosses[bossId].getEntity()];
    return {positionComponent->x, positionComponent->y};
}

void AGame::spawnEnemy(int enemyId, float x, float y) {
    enemies.emplace_back(registry, x, y);

    std::string data = std::to_string(enemyId + 500) + ";" + std::to_string(x) + ";" + std::to_string(y);
    m_server->Broadcast(m_server->createPacket(Network::PacketType::CREATE_ENEMY, data));
}

void AGame::spawnBoss(int bossId, float x, float y) {
    bosses.emplace_back(registry, x, y);

    std::string data = std::to_string(bossId + 900) + ";" + std::to_string(x) + ";" + std::to_string(y);
    m_server->Broadcast(m_server->createPacket(Network::PacketType::CREATE_BOSS, data));
}

void AGame::spawnPlayer(int playerId, float x, float y) {
    if (playerId >= 0 && playerId < 4) {
        players.emplace_back(registry, x, y);

        std::string data = std::to_string(playerId) + ";" + std::to_string(x) + ";" + std::to_string(y);
        std::cout << "Player " << playerId << " spawned at " << x << ", " << y << std::endl;
        m_server->Broadcast(m_server->createPacket(Network::PacketType::CREATE_PLAYER, data));
    }
}

void AGame::spawnBullet(int playerId) {
    if (playerId < players.size()) {
        auto entity = players[playerId].getEntity();
        if (players[playerId].getRegistry().has_component<Position>(entity)) {
            const auto& position = players[playerId].getRegistry().get_components<Position>()[entity];
            bullets.emplace_back(registry, position->x + 50.0f, position->y + 25.0f, 1.0f);

            std::string data = std::to_string((bullets.size() - 1) + 200) + ";" + std::to_string(position->x + 50.0f) + ";" + std::to_string(position->y + 25.0f);
            m_server->Broadcast(m_server->createPacket(Network::PacketType::CREATE_BULLET, data));
        } else {
            std::cerr << "Error: Player " << playerId << " does not have a Position component." << std::endl;
        }
    }
}

void AGame::killPlayers(int entityId) {
    for (auto it = players.begin(); it != players.end();) {
        if (it->getEntity() == entityId) {
            registry.kill_entity(it->getEntity());
            it = players.erase(it);
            std::string data = std::to_string(entityId) + ";0;0";
            m_server->Broadcast(m_server->createPacket(Network::PacketType::DELETE, data));
            break;
        } else {
            ++it;
        }
    }
}

void AGame::killEnemies(int entityId) {
    for (auto it = enemies.begin(); it != enemies.end();) {
        if (it->getEntity() == entityId) {
            registry.kill_entity(it->getEntity());
            it = enemies.erase(it);
            std::string data = std::to_string(entityId + 500) + ";0;0";
            m_server->Broadcast(m_server->createPacket(Network::PacketType::DELETE, data));
            break;
        } else {
            ++it;
        }
    }
}

void AGame::killBullets(int entityId) {
    for (auto it = bullets.begin(); it != bullets.end();) {
        if (it->getEntity() == entityId) {
            registry.kill_entity(it->getEntity());
            it = bullets.erase(it);
            std::string data = std::to_string(entityId + 200) + ";0;0";
            m_server->Broadcast(m_server->createPacket(Network::PacketType::DELETE, data));
            break;
        } else {
            ++it;
        }
    }
}

void AGame::killBosses(int entityId) {
    for (auto it = bosses.begin(); it != bosses.end();) {
        if (it->getEntity() == entityId) {
            registry.kill_entity(it->getEntity());
            it = bosses.erase(it);
            std::string data = std::to_string(entityId + 900) + ";0;0";
            m_server->Broadcast(m_server->createPacket(Network::PacketType::DELETE, data));
            break;
        } else {
            ++it;
        }
    }
}

void AGame::killEntity(int entityId) {
    killPlayers(entityId);
    killEnemies(entityId);
    killBullets(entityId);
    killBosses(entityId);
}

/*
** EPITECH PROJECT, 2024
** R-Type [WSL: Ubuntu]
** File description:
** PacketHandler
*/

#include "PacketHandler.hpp"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <functional>

using namespace Network;

// Constructor
PacketHandler::PacketHandler(ThreadSafeQueue<Network::Packet>& queue, GameState& game, RType::Server& server) : m_queue(queue), m_game(game), m_server(server)
{
    initializeHandlers();
}

PacketHandler::~PacketHandler() {
    stop();
}

void PacketHandler::start() {
    m_running = true;
    m_thread = std::thread(&PacketHandler::processPackets, this);
}

void PacketHandler::stop() {
    m_running = false;
    if (m_thread.joinable())
        m_thread.join();
}

void PacketHandler::processPackets() {
    while (m_running) {
        Network::Packet packet = m_queue.pop();
        handlePacket(packet);
    }
}

void PacketHandler::initializeHandlers() {
    m_handlers[Network::PacketType::NONE] = std::bind(&PacketHandler::handleNone, this, std::placeholders::_1);
    m_handlers[Network::PacketType::REQCONNECT] = std::bind(&PacketHandler::reqConnect, this, std::placeholders::_1);
    m_handlers[Network::PacketType::DISCONNECTED] = std::bind(&PacketHandler::handleDisconnected, this, std::placeholders::_1);
    m_handlers[Network::PacketType::GAME_START] = std::bind(&PacketHandler::handleGameStart, this, std::placeholders::_1);
    m_handlers[Network::PacketType::PLAYER_DEAD] = std::bind(&PacketHandler::handlePlayerDead, this, std::placeholders::_1);
    m_handlers[Network::PacketType::PLAYER_JOIN] = std::bind(&PacketHandler::handlePlayerJoin, this, std::placeholders::_1);
    m_handlers[Network::PacketType::PLAYER_SHOOT] = std::bind(&PacketHandler::handlePlayerShoot, this, std::placeholders::_1);
    m_handlers[Network::PacketType::PLAYER_HIT] = std::bind(&PacketHandler::handlePlayerHit, this, std::placeholders::_1);
    m_handlers[Network::PacketType::PLAYER_SCORE] = std::bind(&PacketHandler::handlePlayerScore, this, std::placeholders::_1);
    m_handlers[Network::PacketType::ENEMY_SPAWNED] = std::bind(&PacketHandler::handleEnemySpawned, this, std::placeholders::_1);
    m_handlers[Network::PacketType::ENEMY_DEAD] = std::bind(&PacketHandler::handleEnemyDead, this, std::placeholders::_1);
    m_handlers[Network::PacketType::ENEMY_MOVED] = std::bind(&PacketHandler::handleEnemyMoved, this, std::placeholders::_1);
    m_handlers[Network::PacketType::ENEMY_SHOOT] = std::bind(&PacketHandler::handleEnemyShoot, this, std::placeholders::_1);
    m_handlers[Network::PacketType::ENEMY_LIFE_UPDATE] = std::bind(&PacketHandler::handleEnemyLifeUpdate, this, std::placeholders::_1);
    m_handlers[Network::PacketType::MAP_UPDATE] = std::bind(&PacketHandler::handleMapUpdate, this, std::placeholders::_1);
    m_handlers[Network::PacketType::GAME_END] = std::bind(&PacketHandler::handleGameEnd, this, std::placeholders::_1);
    m_handlers[Network::PacketType::PLAYER_RIGHT] = std::bind(&PacketHandler::handlePlayerRight, this, std::placeholders::_1);
    m_handlers[Network::PacketType::PLAYER_LEFT] = std::bind(&PacketHandler::handlePlayerLeft, this, std::placeholders::_1);
    m_handlers[Network::PacketType::PLAYER_UP] = std::bind(&PacketHandler::handlePlayerUp, this, std::placeholders::_1);
    m_handlers[Network::PacketType::PLAYER_DOWN] = std::bind(&PacketHandler::handlePlayerDown, this, std::placeholders::_1);
    m_handlers[Network::PacketType::OPEN_MENU] = std::bind(&PacketHandler::handleOpenMenu, this, std::placeholders::_1);
}

void PacketHandler::handlePacket(const Network::Packet &packet) {
    auto it = m_handlers.find(packet.type);
    if (it != m_handlers.end()) {
        it->second(packet);
    } else {
        std::cout << "[PacketHandler] Received unknown packet type." << std::endl;
    }
}

void PacketHandler::handleNone(const Network::Packet &packet)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    std::cout << "[PacketHandler] Handled NONE packet." << std::endl;
}

void PacketHandler::reqConnect(const Network::Packet &packet)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    std::cout << "[PacketHandler] Handled CONNECTED packet." << std::endl;
    auto endpoint = m_server.getRemoteEndpoint();
    m_server.reqConnectData(endpoint);
}

void PacketHandler::handleDisconnected(const Network::Packet &packet)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    std::cout << "[PacketHandler] Handled DISCONNECTED packet." << std::endl;
    auto endpoint = m_server.getRemoteEndpoint();
    m_server.disconnectData(endpoint);
}

void PacketHandler::handleGameStart(const Network::Packet &packet)
{
    int numPlayers;
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        std::cout << "[PacketHandler] Handled GAME_START packet." << std::endl;
        m_server.m_running = true;
        const auto& clients = m_server.getClients();
        numPlayers = clients.size();
        m_server.Broadcast(m_server.createPacket(Network::PacketType::GAME_START, ""));
    }
    std::thread gameThread([this, numPlayers] {
        m_game.run(numPlayers);
    });
    gameThread.detach();
}

void PacketHandler::handlePlayerDead(const Network::Packet &packet)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    std::cout << "[PacketHandler] Handeled PLAYER_DEAD packet." << std::endl;
}

void PacketHandler::handlePlayerJoin(const Network::Packet &packet)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    std::cout << "[PacketHandler] Handeled PLAYER_JOIN packet." << std::endl;
}

void PacketHandler::handlePlayerShoot(const Network::Packet &packet)
{
    // std::lock_guard<std::mutex> lock(m_mutex);
    std::cout << "[PacketHandler] Handeled PLAYER_SHOOT packet." << std::endl;
    const auto& clients = m_server.getClients();
    const udp::endpoint& clientEndpoint = m_server.getRemoteEndpoint();

    size_t playerId = -1;
    bool found = false;
    {
        std::lock_guard<std::mutex> lock(m_server.clients_mutex_);

        for (const auto& [id, client] : clients) {
            if (client.getEndpoint() == clientEndpoint) {
                playerId = id;
                found = true;
                break;
            }
        }
    } if (found) {
        m_game.spawnBullet(playerId);
    } else {
        std::cerr << "[PacketHandler] Client endpoint not found in client list." << std::endl;
    }
}

void PacketHandler::handlePlayerHit(const Network::Packet &packet)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    std::cout << "[PacketHandler] Handeled PLAYER_HIT packet." << std::endl;
}

void PacketHandler::handlePlayerScore(const Network::Packet &packet)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    std::cout << "[PacketHandler] Handeled PLAYER_SCORE packet." << std::endl;
}

void PacketHandler::handleEnemySpawned(const Network::Packet &packet)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    std::cout << "[PacketHandler] Handeled ENEMY_SPAWNED packet." << std::endl;
}

void PacketHandler::handleEnemyDead(const Network::Packet &packet)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    std::cout << "[PacketHandler] Handeled ENEMY_DEAD packet." << std::endl;
}

void PacketHandler::handleEnemyMoved(const Network::Packet &packet)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    std::cout << "[PacketHandler] Handeled ENEMY_MOVED packet." << std::endl;
}

void PacketHandler::handleEnemyShoot(const Network::Packet &packet)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    std::cout << "[PacketHandler] Handeled ENEMY_SHOOT packet." << std::endl;
}

void PacketHandler::handleEnemyLifeUpdate(const Network::Packet &packet)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    std::cout << "[PacketHandler] Handeled ENEMY_LIFE_UPDATE packet." << std::endl;
}

void PacketHandler::handleMapUpdate(const Network::Packet &packet)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    std::cout << "[PacketHandler] Handeled MAP_UPDATE packet." << std::endl;
}

void PacketHandler::handleGameEnd(const Network::Packet &packet)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    std::cout << "[PacketHandler] Handeled GAME_END packet." << std::endl;
}

void PacketHandler::handlePlayerRight(const Network::Packet &packet)
{
    std::cout << "[PacketHandler] Handeled PLAYER_RIGHT packet." << std::endl;
    handlePlayerAction(packet, 2);
}

void PacketHandler::handlePlayerLeft(const Network::Packet &packet)
{
    std::cout << "[PacketHandler] Handeled PLAYER_LEFT packet." << std::endl;
    handlePlayerAction(packet, 1);
}

void PacketHandler::handlePlayerUp(const Network::Packet &packet)
{
    std::cout << "[PacketHandler] Handled PLAYER_UP packet." << std::endl;
    handlePlayerAction(packet, 3);
}

void PacketHandler::handlePlayerDown(const Network::Packet &packet)
{
    std::cout << "[PacketHandler] Handeled PLAYER_DOWN packet." << std::endl;
    handlePlayerAction(packet, 4);
}

void PacketHandler::handleOpenMenu(const Network::Packet &packet)
{
    std::cout << "[PacketHandler] Handeled OPEN_MENU packet." << std::endl;
}

void PacketHandler::handlePlayerAction(const Network::Packet &packet, int action)
{
    {
        std::lock_guard<std::mutex> lock(m_server.clients_mutex_);
        if (!m_server.m_running) {
            std::cout << "[PacketHandler] game is not running, cannot move." << std::endl;
            return;
        }
    }
    std::cout << "[PacketHandler] Handling player action: " << action << std::endl;
    const auto& clients = m_server.getClients();
    const udp::endpoint& clientEndpoint = m_server.getRemoteEndpoint();

    size_t playerId = -1;
    bool found = false;
    {
        std::lock_guard<std::mutex> lock(m_server.clients_mutex_);

        for (const auto& [id, client] : clients) {
            if (client.getEndpoint() == clientEndpoint) {
                playerId = id;
                found = true;
                break;
            }
        }
    }
    if (found) {
        m_game.addPlayerAction(playerId, action);
    } else {
        std::cerr << "[PacketHandler] Client endpoint not found in client list." << std::endl;
    }
}

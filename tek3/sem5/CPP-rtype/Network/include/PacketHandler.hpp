/*
** EPITECH PROJECT, 2024
** R-Type [WSL: Ubuntu]
** File description:
** PacketHandler
*/

#pragma once

#include <thread>
#include <atomic>
#include <functional>
#include <unordered_map>
#include "ThreadSafeQueue.hpp"
#include "Packet.hpp"
#include "PacketType.hpp"
#include "GameState.hpp"
#include "Server.hpp"

namespace Network {
    class PacketHandler {
    public:
        PacketHandler(ThreadSafeQueue<Network::Packet>& queue, GameState& game, RType::Server& server);
        ~PacketHandler();

        void start();
        void stop();
        void processPackets();

        void handlePacket(const Network::Packet &packet);
        void initializeHandlers();

        // handler functions for each packet type
        void handleNone(const Network::Packet &packet);
        void reqConnect(const Network::Packet &packet);
        void handleDisconnected(const Network::Packet &packet);
        void handleGameStart(const Network::Packet &packet);
        void handlePlayerDead(const Network::Packet &packet);
        void handlePlayerJoin(const Network::Packet &packet);
        void handlePlayerShoot(const Network::Packet &packet);
        void handlePlayerHit(const Network::Packet &packet);
        void handlePlayerScore(const Network::Packet &packet);
        void handleEnemySpawned(const Network::Packet &packet);
        void handleEnemyDead(const Network::Packet &packet);
        void handleEnemyMoved(const Network::Packet &packet);
        void handleEnemyShoot(const Network::Packet &packet);
        void handleEnemyLifeUpdate(const Network::Packet &packet);
        void handleMapUpdate(const Network::Packet &packet);
        void handleGameEnd(const Network::Packet &packet);
        void handlePlayerRight(const Network::Packet &packet);
        void handlePlayerLeft(const Network::Packet &packet);
        void handlePlayerUp(const Network::Packet &packet);
        void handlePlayerDown(const Network::Packet &packet);
        void handleOpenMenu(const Network::Packet &packet);
        void handlePlayerAction(const Network::Packet &packet, int action);

    private:
        ThreadSafeQueue<Network::Packet> &m_queue;
        GameState& m_game;
        std::thread m_thread;
        RType::Server& m_server;
        std::atomic<bool> m_running{false};
        std::mutex m_mutex;

        std::unordered_map<Network::PacketType, std::function<void(const Network::Packet&)>> m_handlers;
    };
}
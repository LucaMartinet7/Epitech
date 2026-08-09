/*
** EPITECH PROJECT, 2025
** R-Type [WSL: Ubuntu]
** File description:
** Server
*/

#pragma once

#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <thread>
#include <queue>
#include <map>
#include <boost/asio/steady_timer.hpp>

#include "ThreadSafeQueue.hpp"
#include "Packet.hpp"
#include "ClientRegister.hpp"
#include "GameState.hpp"

typedef std::map<uint32_t, ClientRegister> ClientList;

#define MAX_LENGTH 1024

using namespace boost::placeholders; // Used for Boost.Asio asynchronous operations to bind placeholders for callback functions

namespace RType {
    class Server {
    public:
        Server(boost::asio::io_context& io_context, short port, ThreadSafeQueue<Network::Packet>& packetQueue, GameState* game = nullptr);
        ~Server();
        void handle_receive(const boost::system::error_code& error, std::size_t bytes_transferred);
        void send_to_client(const std::string& message, const boost::asio::ip::udp::endpoint& client_endpoint);

        void setGameState(GameState* game);
        void Broadcast(const std::string& message);
        void playerPacketFactory();
        void enemyPacketFactory();
        void bulletPacketFactory();
        void bossPacketFactory();
        void PacketFactory();
        bool hasPositionChanged(int id, float x, float y, std::unordered_map<int, std::pair<float, float>>& lastKnownPositions);
        Network::ReqConnect reqConnectData(boost::asio::ip::udp::endpoint& client_endpoint);
        Network::DisconnectData disconnectData(boost::asio::ip::udp::endpoint& client_endpoint);
        void handle_game_packet(const Network::Packet& packet, const boost::asio::ip::udp::endpoint& client_endpoint);
        std::string createPacket(const Network::PacketType& type, const std::string& data);
        Network::Packet deserializePacket(const std::string& packet_str);
        const ClientList& getClients() const { return clients_; }
        const udp::endpoint& getRemoteEndpoint() const {
            return remote_endpoint_;
            }
        ClientList clients_;
        uint32_t _nbClients;
        std::mutex clients_mutex_;
        bool m_running;
    private:
        using PacketHandler = std::function<void(const std::vector<std::string>&)>;
        void start_receive();
        uint32_t createClient(boost::asio::ip::udp::endpoint& client_endpoint);
        void start_send_timer(); // Add this line
        void handle_send_timer(const boost::system::error_code& error); // Add this line

        udp::socket socket_;
        udp::endpoint remote_endpoint_;
        std::array<char, 1024> recv_buffer_;
        ThreadSafeQueue<Network::Packet>& m_packetQueue;
        std::unordered_map<std::string, std::function<void(const std::vector<std::string>&)>> packet_handlers_;
        std::unordered_map<Network::PacketType, void(*)(const Network::Packet&)> m_handlers;
        GameState* m_game;
        std::queue<std::string> send_queue_; // Add this line
        boost::asio::steady_timer send_timer_; // Add this line
        std::queue<uint32_t> available_ids_;
    };
}


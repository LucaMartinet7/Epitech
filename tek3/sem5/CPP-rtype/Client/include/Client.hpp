/*
** EPITECH PROJECT, 2024
** R-Type [WSL: Ubuntu]
** File description:
** Client
*/

#pragma once

#include "Packet.hpp"

#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <boost/array.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <array>
#include <thread>
#include <mutex>
#include <csignal>
#include <unordered_map>
#include <boost/asio/steady_timer.hpp>
#include <queue>

#define MAX_LENGTH 1024
#define BASE_AUDIO 50

namespace RType {
    enum class SpriteType {
        Enemy,
        Boss,
        Player,
        Bullet,
        Background,
        Start_button
    };

    class SpriteElement {
    public:
        sf::Sprite sprite;
        int id;
    };

    class Client {
    public:
        Client(boost::asio::io_context& io_context, const std::string& host, short server_port, short client_port);
        ~Client();
        void send(const std::string& message);
        void start_receive();
        int main_loop();
        std::string createPacket(Network::PacketType type);
        void adjustVolume(float change);
        void handleKeyPress(sf::Keyboard::Key key, sf::RenderWindow& window);
        void sendExitPacket() { send(createPacket(Network::PacketType::DISCONNECTED)); }

    private:
        void handle_receive(const boost::system::error_code& error, std::size_t bytes_transferred);
        void handle_send(const boost::system::error_code& error, std::size_t bytes_transferred);
        void run_receive();
        void createSprite();
        void loadTextures();
        void drawSprites(sf::RenderWindow& window);
        void updateSpritePosition();
        void parseMessage(std::string packet_data);
        void destroySprite();
        void processEvents(sf::RenderWindow& window);
        void initLobbySprites(sf::RenderWindow& window);
        void resetValues();
        void LoadSound();
        std::string createMousePacket(Network::PacketType type, int x = 0, int y = 0);
        void start_send_timer();
        void handle_send_timer(const boost::system::error_code& error);

        sf::RenderWindow window;
        boost::asio::ip::udp::socket socket_;
        boost::asio::ip::udp::endpoint server_endpoint_;
        std::array<char, MAX_LENGTH> recv_buffer_;
        std::string received_data;
        std::mutex mutex_;
        std::thread receive_thread_;
        boost::asio::io_context& io_context_;
        std::vector<SpriteElement> sprites_;
        std::unordered_map<SpriteType, sf::Texture> textures_;
        int action;
        int server_id;
        float new_x = 0.0, new_y = 0.0;
        sf::SoundBuffer buffer_background_;
        sf::Sound sound_background_;
        sf::SoundBuffer buffer_shoot_;
        sf::Sound sound_shoot_;
        boost::asio::steady_timer send_timer_;
        std::queue<std::string> send_queue_;
    };
}

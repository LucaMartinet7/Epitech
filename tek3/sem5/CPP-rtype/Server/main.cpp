/*
** EPITECH PROJECT, 2024
** R-Type [WSL: Ubuntu]
** File description:
** main
*/

#include "Server.hpp"
#include "Errors/Throws.hpp"
#include "Packet.hpp"
#include "ThreadSafeQueue.hpp"
#include "PacketHandler.hpp"
#include "GameState.hpp"

short parsePort(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Usage: " << av[0] << " <port>" << std::endl;
        throw RType::InvalidPortException("Invalid number of arguments");
    }
    try {
        return std::stoi(av[1]);
    } catch (const std::exception& e) {
        throw RType::InvalidPortException("Invalid port number");
    }
}

void runServer(short port) {
    try {
        boost::asio::io_context io_context;
        ThreadSafeQueue<Network::Packet> packetQueue;

        RType::Server server(io_context, port, packetQueue, nullptr);

        GameState game(&server);

        server.setGameState(&game);

        Network::PacketHandler packetHandler(packetQueue, game, server);
        packetHandler.start();

        std::cout << "Server started\nListening on UDP port " << port << std::endl;

        std::thread serverThread([&io_context] {
            io_context.run();
        });

        if (serverThread.joinable())
            serverThread.join();

        packetHandler.stop();
    } catch (const boost::system::system_error& e) {
        if (e.code() == boost::asio::error::access_denied) {
            throw RType::PermissionDeniedException("Permission denied");
        } else {
            throw;
        }
    }
}

int main(int ac, char **av)
{
    try {
        short port = parsePort(ac, av);
        runServer(port);
    } catch (const RType::NtsException& e) {
        std::cerr << "Exception: " << e.what() << " (Type: " << e.getType() << ")" << std::endl;
    } catch (const std::exception& e) {
        throw RType::StandardException(e.what());
    } catch (...) {
        throw RType::UnknownException("Unknown exception occurred");
    }
    return 0;
}
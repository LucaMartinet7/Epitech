/*
** EPITECH PROJECT, 2024
** R-Type [WSL: Ubuntu]
** File description:
** main
*/

#include "Client.hpp"

RType::Client* global_client = nullptr;

void signalHandler(int signum) {
    if (global_client) {
        global_client->sendExitPacket();
    }
    std::exit(signum);
}

int main(int ac, char **av)
{
    if (ac != 4) {
        std::cerr << "Usage: " << av[0] << " <host> <server-port> <client-port>" << std::endl;
        return 84;
    }

    std::string host = av[1];
    short server_port = std::stoi(av[2]);
    short client_port = std::stoi(av[3]);

    try {
        boost::asio::io_context io_context;
        RType::Client client(io_context, host, server_port, client_port);

        std::signal(SIGINT, signalHandler);
        client.main_loop();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

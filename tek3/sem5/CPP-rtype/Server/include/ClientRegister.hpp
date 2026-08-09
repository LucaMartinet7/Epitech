/*
** EPITECH PROJECT, 2024
** R-Type [WSL: Ubuntu]
** File description:
** ClientRegister
*/

#pragma once

#include <boost/asio.hpp>

using boost::asio::ip::udp;

class ClientRegister {
    public:
        ClientRegister(size_t id, udp::endpoint endpoint): _id(id), _endpoint(endpoint) {}
        size_t getId() const { return _id; };
        udp::endpoint getEndpoint() const { return _endpoint; };

    private:
        size_t _id;
        udp::endpoint _endpoint;
};

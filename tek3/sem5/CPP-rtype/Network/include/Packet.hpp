/*
** EPITECH PROJECT, 2024
** R-Type [WSL: Ubuntu]
** File description:
** Packet
*/

#pragma once

#include "PacketType.hpp"
#include "Data.hpp"

#include <variant>

namespace Network {

    struct Packet {
        PacketType type;
        std::variant<
            StartData,
            JoinData,
            ReqConnect,
            PositionData,
            PlayerPositionData,
            ScoreData,
            EntityData,
            DisconnectData,
            DeathData,
            BossData
        > data;
    };
}

namespace Network {
    class Manager {
        public:
            Manager() = default;
            ~Manager() = default;
            // void createPacket(PacketType type, void *data);

        private:
    };
}

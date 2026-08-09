/*
** EPITECH PROJECT, 2024
** R-Type [WSL: Ubuntu]
** File description:
** Data
*/

#pragma once

#define MAX_PLAYERS 2

#include <iostream>

namespace Network {
        extern "C"
        {
            struct StartData {
                public:
                    int id;
            };
            struct JoinData {
                public:
                    int id;
            };
            struct ReqConnect {
                public:
                    int id;
            };
            struct PositionData {
                public:
                    std::string direction;
                    float x;
                    float y;
            };
            struct PlayerPositionData {
                public:
                    PositionData pos[MAX_PLAYERS];
            };
            struct ScoreData {
                public:
                    int score;
            };
            struct EntityData {
                public:
                    int id;
                    char type;
                    PositionData pos;
                    float vx;
                    float vy;
            };
            struct DisconnectData {
                public:
                    int id;
            };
            struct DeathData {
                public:
                    int id;
                    char reason;
            };
            struct BossData {
                public:
                    int id;
                    PositionData pos;
                    int alive;
            };
    }
}
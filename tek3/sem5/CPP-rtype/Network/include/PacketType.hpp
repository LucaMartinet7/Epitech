/*
** EPITECH PROJECT, 2024
** R-Type [WSL: Ubuntu]
** File description:
** PacketType
*/

#pragma once

#include <cstdint>

#include "Packet.hpp"

namespace Network {
    enum class PacketType {
        NONE = 0,
        REQCONNECT = 1,
        DISCONNECTED = 2,
        GAME_START = 3,
        PLAYER_DEAD = 4,
        PLAYER_JOIN = 5,
        PLAYER_SHOOT = 6,
        PLAYER_HIT = 7,
        PLAYER_SCORE = 8,
        ENEMY_SPAWNED = 9,
        ENEMY_DEAD = 10,
        ENEMY_MOVED = 11,
        ENEMY_SHOOT = 12,
        ENEMY_LIFE_UPDATE = 13,
        MAP_UPDATE = 14,
        GAME_END = 15,      //
        PLAYER_RIGHT = 16,  //no pos
        PLAYER_LEFT = 17,   //no pos
        PLAYER_UP = 18,     //no pos
        PLAYER_DOWN = 19,   //no pos
        OPEN_MENU = 20,     //no pos
        MOUSE_CLICK = 21,   //pos
        CREATE_ENEMY = 22,
        CREATE_BOSS = 23,
        CREATE_PLAYER = 24,
        CREATE_BULLET = 25,
        BACKGROUND = 26,
        CREATE_POWERUP = 27,
        DELETE = 28,
        CHANGE = 29,
        GAME_STARTED = 30,
        GAME_NOT_STARTED = 31,
    };
}

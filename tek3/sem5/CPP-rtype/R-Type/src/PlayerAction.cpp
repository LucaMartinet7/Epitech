/*
** EPITECH PROJECT, 2025
** R-Type [WSL: Ubuntu]
** File description:
** PlayerAction
*/

#include "PlayerAction.hpp"

PlayerAction::PlayerAction(int player_id, int action_id)
    : player_id(player_id), action_id(action_id), processed(false) {}

PlayerAction::~PlayerAction() {}

int PlayerAction::getId() const {
    return player_id;
}

void PlayerAction::setId(int player_id) {
    this->player_id = player_id;
}

int PlayerAction::getActionId() const {
    return action_id;
}

void PlayerAction::setActionId(int action_id) {
    this->action_id = action_id;
}

bool PlayerAction::getProcessed() const {
    return processed;
}

void PlayerAction::setProcessed(bool value) {
    this->processed = value;
}

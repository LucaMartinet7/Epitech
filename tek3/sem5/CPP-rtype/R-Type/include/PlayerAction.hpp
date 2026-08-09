/*
** EPITECH PROJECT, 2025
** R-Type [WSL: Ubuntu]
** File description:
** PlayerAction
*/

#ifndef PLAYERACTION_HPP
#define PLAYERACTION_HPP

class PlayerAction {
private:
    int player_id;
    int action_id;
    bool processed;

public:
    PlayerAction(int player_id, int action_id);
    ~PlayerAction();

    int getId() const;
    void setId(int player_id);

    int getActionId() const;
    void setActionId(int action_id);

    bool getProcessed() const;
    void setProcessed(bool value);
};

#endif // PLAYERACTION_HPP

/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** eventsManager
*/

#include "CentipedeGame.hpp"
#include "AEvent.hpp"

void arcade::CentipedeGame::manageEvent(std::vector<std::unique_ptr<arcade::IEvent>> const &events)
{
    for (auto &event : events) {
        if (event->type() == "Up")
            _charDir = arcade::Direction::UP;
        else if (event->type() == "Down")
            _charDir = arcade::Direction::DOWN;
        else if (event->type() == "Left")
            _charDir = arcade::Direction::LEFT;
        else if (event->type() == "Right")
            _charDir = arcade::Direction::RIGHT;
        else if (event->type() == "Escape")
            _charDir = arcade::Direction::PAUSE;
        else if (event->type() == "Space")
            _fired = true;
        else if (event->type() == "Restart")
            restartGame();
    }
}

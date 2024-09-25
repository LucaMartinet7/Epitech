/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** eventsManager
*/

#include "SnakeGame.hpp"
#include "AEvent.hpp"

void arcade::SnakeGame::manageEvent(std::vector<std::unique_ptr<arcade::IEvent>> const &events)
{
    for (auto &event : events) {
        if (event->type() == "Up" && _snakeDir != arcade::Direction::DOWN) {
            _snakeDir = arcade::Direction::UP;
            return;
        } else if (event->type() == "Down" && _snakeDir != arcade::Direction::UP) {
            _snakeDir = arcade::Direction::DOWN;
            return;
        } else if (event->type() == "Left" && _snakeDir != arcade::Direction::RIGHT) {
            _snakeDir = arcade::Direction::LEFT;
            return;
        } else if (event->type() == "Right" && _snakeDir != arcade::Direction::LEFT) {
            _snakeDir = arcade::Direction::RIGHT;
            return;
        } else if (event->type() == "Escape") {
            _snakeDir = arcade::Direction::PAUSE;
            return;
        } else if (event->type() == "Restart") {
            restartGame();
            return;
        }
    }
}

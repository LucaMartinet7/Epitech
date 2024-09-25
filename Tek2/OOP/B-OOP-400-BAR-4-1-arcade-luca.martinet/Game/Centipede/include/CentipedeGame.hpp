/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** CentipedeGame
*/

#include <chrono>
#include <vector>
#include <utility>

#include "IArcade.hpp"
#include "AObject.hpp"
#include "AEvent.hpp"

#ifndef _CENTIPEDEGAME_HPP
    #define _CENTIPEDEGAME_HPP

#define MAP_SIZE_X 41
#define MAP_SIZE_Y 27

#define PLAYER_COLOR {255, 0, 0}
#define LAZER_COLOR {0, 255, 0}
#define CENTIPEDE_COLOR     {240, 243, 0}
#define WALL_COLOR      {99, 115, 0}
#define NOTHING_COLOR   {0, 0, 0}

#define CENTIPEDE_LEN       5

#define OBJECT_SIZE     {1, 1}

#define COOLDOWN        100
#define LAZER_COOLDOWN  50

namespace arcade {
    enum class Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        PAUSE
    };
    enum class Level {
        ONE,
        TWO,
        THREE
    };

    class CentipedeGame : public IGameModule{
        public:

            CentipedeGame();
            void manageEvent(std::vector<std::unique_ptr<IEvent>> const &) override;
            void iterate(void) override;
            data_t const &getMap(void) const override;

            void createMap(void);
            void restartGame(void);

            void updateCentipede(std::vector<std::array<int, 2>> pos, std::array<int, 3> RGB);
            void updatePlayer(std::array<int, 2> pos, std::array<int, 3> RGB);
            void updateLazer(std::array<int, 2> pos, std::array<int, 3> RGB);

            void movePlayer();
            void moveLazer();
            void moveCentipede();
            void fireLazer();

            bool isWall(const std::array<int, 2>& pos);
            void updateCentipedeVisualRepresentation();

            ~CentipedeGame();
        private:
            data_t _map;
            size_t _points;
            size_t _it;

            std::chrono::_V2::system_clock::time_point _lastIteranceTime;
            std::chrono::system_clock::time_point _lastLazerMoveTime;

            std::vector<std::array<int, 2>> _centipedePos;
            std::vector<std::vector<std::array<int, 2>>> _centipedes;
            Direction _centipedeDir;

            Direction _charDir;
            std::array<int, 2> _playerPos;
            std::array<int, 2> _lazerPos;
            bool _fired;
    };
}

#endif /* !_CENTIPEDEGAME_HPP */

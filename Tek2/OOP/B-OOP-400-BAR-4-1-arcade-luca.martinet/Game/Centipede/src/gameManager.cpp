/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** game
*/

#include "CentipedeGame.hpp"
#include "AObject.hpp"
#include <algorithm>

void arcade::CentipedeGame::iterate()
{
   auto currentTime = std::chrono::system_clock::now();

    if (std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - _lastIteranceTime).count() < COOLDOWN)
        return;
    _lastIteranceTime = currentTime;
    if (_charDir != arcade::Direction::PAUSE) {
        movePlayer();
        moveLazer();
        moveCentipede();
    }
    updatePlayer(_playerPos, PLAYER_COLOR);
    updateLazer(_lazerPos, LAZER_COLOR);
    updateCentipede(_centipedePos, CENTIPEDE_COLOR);
    if (_fired)
        fireLazer();
    _fired = false;
    _it++;
}

void arcade::CentipedeGame::movePlayer()
{
    std::array<int, 2> newPos = _playerPos;

    switch (_charDir) {
        case arcade::Direction::UP:
            if (newPos[1] > MAP_SIZE_Y * 0.8)
                newPos[1] -= 1;
            break;
        case arcade::Direction::DOWN:
            newPos[1] += 1;
            break;
        case arcade::Direction::LEFT:
            newPos[0] -= 1;
            break;
        case arcade::Direction::RIGHT:
            newPos[0] += 1;
            break;
        default:
            return;
    }
    if (isWall(newPos))
        return;
    _playerPos = newPos;
}

void arcade::CentipedeGame::moveCentipede()
{
    for (size_t i = _centipedePos.size() - 1; i > 0; --i)
        _centipedePos[i] = _centipedePos[i - 1];
    if (_centipedeDir == arcade::Direction::RIGHT)
        _centipedePos[0][0] += 1;
    else if (_centipedeDir == arcade::Direction::LEFT)
        _centipedePos[0][0] -= 1;
    if (isWall(_centipedePos[0])) {
        _centipedeDir = (_centipedeDir == arcade::Direction::RIGHT) ? arcade::Direction::LEFT : arcade::Direction::RIGHT;
        _centipedePos[0][1] += 1;
    }
    for (size_t i = 1; i < _centipedePos.size(); ++i) {
        if (isWall(_centipedePos[i]))
            _centipedePos[i][1] += 1;
    }
}

void arcade::CentipedeGame::moveLazer()
{
    auto currentTime = std::chrono::system_clock::now();
    if (std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - _lastLazerMoveTime).count() < LAZER_COOLDOWN)
        return;
    _lastLazerMoveTime = currentTime;
    if (_lazerPos[0] == -1 && _lazerPos[1] == -1)
        return;
    if (isWall(_lazerPos)) {
        updateLazer(_lazerPos, NOTHING_COLOR);
        _lazerPos = {-1, -1};
        _fired = false;
        return;
    }
    auto it = std::find(_centipedePos.begin(), _centipedePos.end(), _lazerPos);
    if (it != _centipedePos.end()) {
        *it = {_lazerPos[0], _lazerPos[1]};
        updateCentipedeVisualRepresentation();
        updateLazer(_lazerPos, NOTHING_COLOR);
        _lazerPos = {-1, -1};
        _fired = false;
        return;
    }
    if (_lazerPos[1] > 0) {
        updateLazer(_lazerPos, NOTHING_COLOR);
        _lazerPos[1] -= 1;
    } else {
        updateLazer(_lazerPos, NOTHING_COLOR);
        _lazerPos = {-1, -1};
        _fired = false;
    }
}

void arcade::CentipedeGame::updateCentipedeVisualRepresentation()
{
    auto it = std::find(_centipedePos.begin(), _centipedePos.end(), _lazerPos);
    if (it != _centipedePos.end()) {
        std::vector<std::array<int, 2>> beforeCentipede, afterCentipede;
        size_t splitPosition = it - _centipedePos.begin();
        for (size_t i = 0; i < _centipedePos.size(); ++i) {
            if (i < splitPosition)
                beforeCentipede.push_back(_centipedePos[i]);
            else if (i > splitPosition)
                afterCentipede.push_back(_centipedePos[i]);
        }
        if (!beforeCentipede.empty())
            _centipedes.push_back(beforeCentipede);
        if (!afterCentipede.empty())
            _centipedes.push_back(afterCentipede);
        _centipedePos.erase(it);
        std::unique_ptr<arcade::AObject> wallObj = std::make_unique<arcade::AObject>();
        wallObj->setPos(*it);
        wallObj->setSize(OBJECT_SIZE);
        wallObj->setRGB(WALL_COLOR);
        wallObj->setAscii('5');
        wallObj->setAsset("Assets/centipede/5.png");
        wallObj->setType(arcade::Type::Graphic);
        _map.objects.push_back(std::move(wallObj));
        for (auto& centipede : _centipedes) {
            auto segmentIt = std::find(centipede.begin(), centipede.end(), *it);
            if (segmentIt != centipede.end())
                centipede.erase(segmentIt);
        }
    }
}

void arcade::CentipedeGame::fireLazer()
{
    if (_fired && _lazerPos[0] == -1 && _lazerPos[1] == -1) {
        _lazerPos = _playerPos;
        _fired = false;
    }
}

bool arcade::CentipedeGame::isWall(const std::array<int, 2>& pos)
{
    for (auto &obj : _map.objects) {
        if (obj->getPos() == pos && obj->getAscii() == '5') {
            return true;
        }
    }
    return false;
}

void arcade::CentipedeGame::restartGame(void)
{
    _map.objects.clear();
    createMap();
}

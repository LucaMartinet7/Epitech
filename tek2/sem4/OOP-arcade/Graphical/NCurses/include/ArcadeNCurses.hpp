/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** ArcadeNCurses
*/

#include <ncurses.h>
#include <map>

#include "IArcade.hpp"

#ifndef _ARCADENCURSES_HPP
    #define _ARCADENCURSES_HPP

#define WINDOW_WIDTH 80
#define WINDOW_HEIGHT 24

namespace arcade {
    class ArcadeNCurses : public IDisplayModule{
        public:
            ArcadeNCurses();
            void display(const data_t& data) override;
            void clear(void) override;
            std::vector<std::unique_ptr<IEvent>> const &getEvent(void) override;

            void setKeyMap(void);
            ~ArcadeNCurses();

        protected:
            std::map<int, std::string> _keyMap;
            std::vector<std::unique_ptr<IEvent>> _events;
    };
}

#endif /* !_ARCADENCURSES_HPP */

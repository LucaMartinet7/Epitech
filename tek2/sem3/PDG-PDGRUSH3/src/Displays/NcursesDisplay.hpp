/*
** EPITECH PROJECT, 2024
** paradigms day13
** File description:
** NCursesDisplay.hpp
*/

#ifndef _NCURSESDISPLAY_HPP
    #define _NCURSESDISPLAY_HPP

#include <ncurses.h>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <sstream>

#include "IDisplay.hpp"

namespace Krell {
    class NCursesDisplay : public IDisplay {
        public:
            NCursesDisplay();
            ~NCursesDisplay() override;

            void show(int width);
            void update(IModule* updatedModule);
            void setModule(IModule* module);
        private:
            std::vector<std::string> splitString(const std::string &str, char delimiter) const;
            std::vector<IModule *> _modules;
            std::size_t _coreNumber;
    };
}

#endif /* !_NCURSESDISPLAY_HPP */

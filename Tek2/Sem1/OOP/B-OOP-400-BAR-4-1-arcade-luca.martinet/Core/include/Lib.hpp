/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** Lib
*/

#include <unordered_map>

#include "IArcade.hpp"

#ifndef _LIB_HPP
    #define _LIB_HPP

bool is_display_lib(const std::string &filename);
bool is_game_lib(const std::string &filename);

namespace arcade {
    enum class libType {
        Graphic,
        Game
    };

    class Lib {
        public:
            Lib();
            void findDisplayLib(void);
            void findGamesLib(void);
            void setModule(std::string libName, libType mode);
            void loadModule(std::string libName, libType mode);
            void loadNextModule(libType mode);
            void selectFirstLib(std::string libName);

            void createMenu(void);
            bool manageMenuEvent(std::vector<std::unique_ptr<arcade::IEvent>> const& events);
            void updateMenu(void);
            void clearMenu(void);
            ~Lib();

            std::unique_ptr<arcade::IDisplayModule> _displayModuleActive;
            std::unique_ptr<arcade::IGameModule> _gameModuleActive;
            data_t _menu;
        protected:
            data_t _map;
            int _selectedDisplay;
            int _selectedGame;
            int _cursorCol;
            int _cursorRow;
            void *_dispHandle;
            void *_gameHandle;
            std::vector<std::string> _displayModuleList;
            std::vector<std::string> _GameModuleList;
    };
}

#endif /* !_LIB_HPP */

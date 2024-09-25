/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** Core
*/

#include <memory>

#include "IArcade.hpp"
#include "Lib.hpp"

#ifndef _CORE_HPP
    #define _CORE_HPP

namespace arcade {
    class Core {
        public:
            Core();
            void init(char *libPath);
            void loop(void);

            bool eventManager(std::vector<std::unique_ptr<arcade::IEvent>> const& events);
            ~Core();

        protected:
        private:
            Lib lib;
            bool _isMenu;
            std::unique_ptr<arcade::IDisplayModule> _selectedDisplayModule;
            std::unique_ptr<arcade::IGameModule> _selectedGameModule;
    };
}

#endif /* !_CORE_HPP */

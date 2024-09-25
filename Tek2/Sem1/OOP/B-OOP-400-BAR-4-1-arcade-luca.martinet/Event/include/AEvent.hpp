/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** AEvent
*/

#include "IArcade.hpp"

#ifndef _AEVENT_HPP
    #define _AEVENT_HPP

namespace arcade {
    class AEvent : public arcade::IEvent{
        public:
            AEvent(std::string type);
            const std::string &type() const override;
            ~AEvent();

        protected:
            std::string _type;
    };
}

#endif /* !_AEVENT_HPP */

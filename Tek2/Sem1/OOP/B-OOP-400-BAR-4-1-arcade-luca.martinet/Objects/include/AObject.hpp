/*
** EPITECH PROJECT, 2024
** B-OOP-400-BAR-4-1-arcade-luca.martinet
** File description:
** AObject
*/

#include "IArcade.hpp"

#ifndef _AOBJECT_HPP_
    #define _AOBJECT_HPP_

namespace arcade {
    class AObject : public arcade::IObject{
        public:
            AObject();
            std::array<int, 3> const &getRGB(void) const override;
            std::array<int, 2> const &getPos(void) const override;
            std::array<int, 2> const &getSize(void) const override;
            std::string const &getAsset(void) const override;
            char getAscii(void) const override;
            arcade::Type getType(void) const override;

            void setRGB(std::array<int, 3> rgb);
            void setPos(std::array<int, 2> pos);
            void setSize(std::array<int, 2> size);
            void setAsset(std::string asset);
            void setAscii(char ascii);
            void setType(arcade::Type type);
            ~AObject();
        protected:
            std::array<int, 3> _rgb;
            std::array<int, 2> _pos;
            std::array<int, 2> _size;
            std::string _asset;
            char _ascii;
            arcade::Type _type;
    };
}

#endif /* !_AOBJECT_HPP_ */

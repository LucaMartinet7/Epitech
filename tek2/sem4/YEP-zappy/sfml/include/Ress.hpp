/*
** EPITECH PROJECT, 2024
** B-YEP-400-BAR-4-1-zappy-noe.kurata
** File description:
** Ress
*/

#ifndef RESS_HPP_
    #define RESS_HPP_

    #include <iostream>
    #include <SFML/Graphics.hpp>

class Ress {
    public:
        Ress() = default;
        ~Ress() = default;
        void initializeRess(std::string name);
        bool layEgg();
        bool operator==(const Ress& other) const { return _name == other._name; }
        std::string _name;
    protected:
        float _density = 0;
        sf::Sprite _sprite;
        sf::Texture _texture;
};

namespace std {
    template<> struct hash<Ress> {
        size_t operator()(const Ress& ress) const {
            return std::hash<std::string>()(ress._name); // Corrected usage
        }
    };
}

#endif /* !RESS_HPP_ */

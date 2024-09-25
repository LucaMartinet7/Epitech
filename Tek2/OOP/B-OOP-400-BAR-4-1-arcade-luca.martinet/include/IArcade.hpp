/*
** EPITECH PROJECT, 2024
** include
** File description:
** arcade
*/

#include <iostream>
#include <vector>
#include <array>
#include <memory>

#ifndef AZE_HPP_
    #define AZE_HPP_

namespace arcade {
    enum Type {
        Graphic,
        Text
    };

    class IObject {
        public:
            virtual ~IObject() = default;
            virtual std::array<int, 3> const &getRGB(void) const = 0;
            virtual std::array<int, 2> const &getPos(void) const = 0;
            virtual std::array<int, 2> const &getSize(void) const = 0;
            virtual std::string const &getAsset(void) const = 0;
            virtual char getAscii(void) const = 0;
            virtual Type getType(void) const = 0;
    };

    class IEvent {
        public:
            virtual ~IEvent() = default;
            virtual const std::string &type() const = 0;
    };

    typedef struct data_s {
        std::vector<std::unique_ptr<IObject>> objects;
        std::pair<int, int> size;
    } data_t;

    class IDisplayModule {
        public :
            virtual ~IDisplayModule() = default;
            virtual void display(const data_t& data) = 0;
            virtual void clear(void) = 0;
            virtual std::vector<std::unique_ptr<IEvent>> const &getEvent(void) = 0;
    };

    class IGameModule {
        public:
            virtual ~IGameModule() = default;
            virtual void manageEvent(std::vector<std::unique_ptr<IEvent>> const &) = 0;
            virtual void iterate(void) = 0;
            virtual data_t const &getMap(void) const = 0;
    };
}

#endif /* !AZE_HPP_ */

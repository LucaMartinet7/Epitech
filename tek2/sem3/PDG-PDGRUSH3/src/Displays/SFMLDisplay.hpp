/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGRUSH3-jules.dufraiche
** File description:
** SFMLDisplay
*/

#ifndef SFML_HPP_
    #define SFML_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

#include "IDisplay.hpp"

namespace Krell {
    class SFMLDisplay : public IDisplay {
        public:
            SFMLDisplay();
            ~SFMLDisplay() override;

            void show(int width);
            void update(IModule* updatedModule);
            void setModule(IModule* module);
        private:
            struct CoreInfo {
                std::string model;
                double frequency;
                };

                class Cpu {
                public:
                    std::vector<CoreInfo> coreInfoList;
                    double globalFrequency;
                    int numPhysicalCPUs;
                    int numVirtualCPUs;
                    unsigned int total_cores;
                    std::string data;
                };
            sf::Text SetTitle(std::string title, unsigned int x, unsigned int y);
            sf::RectangleShape SetFilledBar(unsigned int batteryPercentage, unsigned int x, unsigned int y);
            sf::RectangleShape SetEmptyBar(unsigned int x, unsigned y);
            sf::Text createPercentageText(sf::RectangleShape ramBar, unsigned int batteryPercentage);
            sf::Text setText(std::string w1, unsigned int x, unsigned int y);
            void drawSystemInfo(std::string username, std::string hostname, std::string os, std::string kernel, std::string time);
            void drawCpu(const Cpu &Cpu);
            void drawRam(unsigned int ramFrequency, unsigned int ramPercentage);
            void drawBattery(unsigned int batteryPercentage, std::string batteryState);
            sf::RectangleShape initializeRectangle(sf::Vector2f size, float x, float y);
            sf::RenderWindow _window;
            std::vector<std::vector<sf::RectangleShape>> _rectangles;
            sf::Font _font;
            std::vector<IModule *> _modules;

    };
}

#endif /* !SFML_HPP_ */

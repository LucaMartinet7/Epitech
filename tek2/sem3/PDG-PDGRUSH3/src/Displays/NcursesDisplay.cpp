#include "NcursesDisplay.hpp"

namespace Krell {
    NCursesDisplay::NCursesDisplay(void)
    {
        return;
    }

    NCursesDisplay::~NCursesDisplay(void)
    {
        return;
    }

    std::vector<std::string> NCursesDisplay::splitString(const std::string &str, char delimiter) const
    {
        std::vector<std::string> tokens;
        std::istringstream tokenStream(str);
        std::string token;
        while (std::getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    void NCursesDisplay::show(int width)
    {
        int num_columns = 2;
        int box_height = 5;
        int box_width = width / num_columns - 3;
        int num_modules = this->_modules.size();

        for (int i = 0; i < num_modules; ++i) {
            if (this->_modules.at(i)->getName().c_str() == std::string("CPU Module")) {
                box_height = 21;
                int col = i % num_columns;
                int row = i / num_columns;
                int x = 1;
                int y = row * (9) + 1;

                box_width = width - 3;
                if (width < 80) {
                    x = 1;
                    y = i * (box_height + 1) + 1;
                }
                mvhline(y, x, 0, box_width);
                mvhline(y + box_height - 1, x, 0, box_width);
                mvvline(y, x, 0, box_height);
                mvvline(y, x + box_width - 1, 0, box_height);
                mvaddch(y, x, ACS_ULCORNER);
                mvaddch(y, x + box_width - 1, ACS_URCORNER);
                mvaddch(y + box_height - 1, x, ACS_LLCORNER);
                mvaddch(y + box_height - 1, x + box_width - 1, ACS_LRCORNER);
                std::string data = this->_modules.at(i)->getData();
                std::vector<std::string> lines = splitString(data, '\n');
                for (size_t lineIndex = 0; lineIndex < lines.size(); ++lineIndex) {
                    mvprintw(y + lineIndex + 1, x + 2, lines[lineIndex].c_str());
                }
                mvprintw(y, x + 2, " %s ", this->_modules.at(i)->getName().c_str());
                box_height = 5;
                continue;
            }
            box_height = 5;

            int col = i % num_columns;
            int row = i / num_columns;
            int x = col * (box_width + 3) + 1;
            int y = row * (box_height + 1) + 1;
            if (width < 80) {
                x = 1;
                y = i * (box_height + 1) + 1;

                box_width = width - 3;
            }
            mvhline(y, x, 0, box_width);
            mvhline(y + box_height - 1, x, 0, box_width);
            mvvline(y, x, 0, box_height);
            mvvline(y, x + box_width - 1, 0, box_height);
            mvaddch(y, x, ACS_ULCORNER);
            mvaddch(y, x + box_width - 1, ACS_URCORNER);
            mvaddch(y + box_height - 1, x, ACS_LLCORNER);
            mvaddch(y + box_height - 1, x + box_width - 1, ACS_LRCORNER);
            mvprintw(y + box_height / 2, x + 1, " %s ", this->_modules.at(i)->getData().c_str());
            mvprintw(y, x + 2, " %s ", this->_modules.at(i)->getName().c_str());
        }
    }

    void NCursesDisplay::update(IModule* updatedModule)
    {
        for (auto &module : this->_modules) {
            if (module->getName() == updatedModule->getData()) {
                IModule* tmp = module;
                module = updatedModule;
                delete tmp;
            }
        }
    }

    void NCursesDisplay::setModule(IModule* module)
    {
        for (auto &m : this->_modules) {
            if (m == module)
                return;
        }
        this->_modules.push_back(module);
    }
}

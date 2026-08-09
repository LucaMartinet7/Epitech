
#include <iostream>
#include <string>
#include "Modules/RAMModule.hpp"
#include "Modules/BatteryModule.hpp"
#include "Modules/HostnameUsernameModule.hpp"
#include "Modules/OSKernelModule.hpp"
#include "Modules/DateTimeModule.hpp"
#include "Modules/CPUModule.hpp"

#include "Displays/NcursesDisplay.hpp"
#include "Displays/SFMLDisplay.hpp"

static int startSFML(void)
{
    Krell::RAMModule ramModule;
    Krell::BatteryModule batModule;
    Krell::HostUserModule usrModule;
    Krell::OSKernelModule oskModule;
    Krell::ClockModule clkModule;
    Krell::CPUModule cpuModule;
    Krell::SFMLDisplay disp;

    disp.setModule(&ramModule);
    disp.setModule(&batModule);
    disp.setModule(&usrModule);
    disp.setModule(&oskModule);
    disp.setModule(&clkModule);
    disp.setModule(&cpuModule);

    disp.show(0);
    return 0;
}

static int startNcurses(void)
{
    Krell::RAMModule ramModule;
    Krell::BatteryModule batModule;
    Krell::HostUserModule usrModule;
    Krell::OSKernelModule oskModule;
    Krell::ClockModule clkModule;
    Krell::CPUModule cpuModule;
    Krell::NCursesDisplay disp;

    disp.setModule(&ramModule);
    disp.setModule(&batModule);
    disp.setModule(&usrModule);
    disp.setModule(&oskModule);
    disp.setModule(&clkModule);
    disp.setModule(&cpuModule);

    initscr();
    cbreak();
    noecho();

    WINDOW *mainwin = newwin(0, 0, 0, 0);
    nodelay(mainwin, TRUE);
    keypad(mainwin, TRUE);

    curs_set(0);

    timeout(1000);

    while (true) {
        ramModule.update();
        batModule.update();
        usrModule.update();
        oskModule.update();
        clkModule.update();
        cpuModule.update();
        clear();

        int desired_width = getmaxx(mainwin);


        if (desired_width < 40) {
            mvprintw(0, 6, "Enlarge the screen");
        } else {
            disp.show(desired_width);
        }

        refresh();
        int ch = getch();

        if (ch != ERR) {
            if (ch == 'q') {
                break;
            }
        }

    }

    curs_set(1);
    endwin();
    return 0;
}

int main(int ac, char **av)
{
    for (int i = 0; i < ac; i++) {
        if (av[i] == std::string("-g")) {
            return startSFML();
        } else if (av[i] == std::string("-t")) {
            return startNcurses();
        }
    }
    return startNcurses();
}

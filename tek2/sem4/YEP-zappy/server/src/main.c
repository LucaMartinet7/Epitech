/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Main server Zappy
*/

#include "player.h"

void help(void)
{
    printf("USAGE:\n\t./zappy_server -p port -x width -y height"
        " -n name1 name2 ... -c clientsNb -f freq\n\nDESCRIPTION:\n");
    printf("\t-p port\t\t\t\tport number\n");
    printf("\t-x width\t\t\twidth of the world\n");
    printf("\t-y height\t\t\theight of the world\n");
    printf("\t-n name1 name2 ...\t\tname of the team\n");
    printf("\t-c clientsNb\t\t\tnumber of authorized clients per team\n");
    printf("\t-f freq\t\t\t\treciprocal of time unit for ");
    printf("execution of actions\n");
}

int main(int ac, char **av)
{
    server_t *server;
    player_t **player;

    if (ac == 2 && strcmp(av[1], "-help") == 0) {
        help();
        return (0);
    }
    if (check_errors(ac, av) == 84) {
        return (84);
    }
    server = set_value(av);
    player = malloc(sizeof(player_t *) * 30);
    return (start_server(av, server, player));
}

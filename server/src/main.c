/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** main.c
*/

#include <string.h>
#include "zappy_server.h"

static void zappy_free(zappy_server_t *server)
{
    free_teams(server);
}

int main(int argc, char *argv[])
{
    zappy_server_t server;
    int res = 0;

    memset(&server, 0, sizeof(server));
    if (check_help(argc, argv)) {
        return 0;
    }
    res = parse_args(argc, argv, &server);
    zappy_free(&server);
    return (res ? 0 : 84);
}

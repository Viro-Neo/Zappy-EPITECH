/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** resources.c
*/

#include <stdlib.h>
#include <string.h>
#include "zappy_server.h"

static int *get_random_tile(zappy_server_t *server)
{
    int y = rand() % server->height;
    int x = rand() % server->width;

    return server->map[y][x];
}

void spawn_resources(zappy_server_t *server)
{
    int resources[7] = {
        server->width * server->height * 0.5f,
        server->width * server->height * 0.3f,
        server->width * server->height * 0.15f,
        server->width * server->height * 0.1f,
        server->width * server->height * 0.1f,
        server->width * server->height * 0.08f,
        server->width * server->height * 0.05f
    };
    int *tile = NULL;

    for (int i = 0; i < 7; ++i) {
        while (resources[i] > 0) {
            tile = get_random_tile(server);
            ++tile[i];
            --resources[i];
        }
    }
}

int get_resource_index(const char *str)
{
    if (strcmp(str, "food") == 0)
        return 0;
    if (strcmp(str, "linemate") == 0)
        return 1;
    if (strcmp(str, "deraumere") == 0)
        return 2;
    if (strcmp(str, "sibur") == 0)
        return 3;
    if (strcmp(str, "mendiane") == 0)
        return 4;
    if (strcmp(str, "phiras") == 0)
        return 5;
    if (strcmp(str, "thystame") == 0)
        return 6;
    return -1;
}

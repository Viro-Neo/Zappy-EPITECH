/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** player_incantation.c
*/

#include <stdio.h>
#include "zappy_server.h"

static int can_elevate(zappy_client_t *client)
{
    (void)client;
    return 0;
}

int can_elevation_start(zappy_client_t *client)
{
    if (can_elevate(client)) {
        return 1;
    }
    dprintf(client->sockfd, "ko\n");
    return 0;
}

void player_incantation(zappy_client_t *client, char *)
{
    if (can_elevate(client)) {
        ++client->player.lvl;
        dprintf(client->sockfd, "ok\n");
    } else {
        dprintf(client->sockfd, "ko\n");
    }
}

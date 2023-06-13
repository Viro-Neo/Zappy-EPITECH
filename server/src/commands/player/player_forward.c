/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** player_forward.c
*/

#include <stdio.h>
#include "zappy_server.h"

void player_forward(zappy_client_t *client, char *)
{
    if (client->player.rot == 1) {
        ++client->player.y;
    }
    if (client->player.rot == 2) {
        ++client->player.x;
    }
    if (client->player.rot == 3) {
        --client->player.y;
    }
    if (client->player.rot == 4) {
        --client->player.x;
    }
    client->player.x %= client->server->width;
    client->player.y %= client->server->height;
    dprintf(client->sockfd, "ok\n");
}

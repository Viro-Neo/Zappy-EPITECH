/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** player_incantation.c
*/

#include <stdio.h>
#include "zappy_server.h"

static int meet_conditions(zappy_client_t *client, int elevation)
{
    static int elev[7][7] = {
        { 1, 1, 0, 0, 0, 0, 0 }, { 2, 1, 1, 1, 0, 0, 0 },
        { 2, 2, 0, 1, 0, 2, 0 }, { 4, 1, 1, 2, 0, 1, 0 },
        { 4, 1, 2, 1, 3, 0, 0 }, { 6, 1, 2, 3, 0, 1, 0 },
        { 6, 2, 2, 2, 2, 2, 1 },
    };
    int l = client->player.lvl - 1;
    int x = client->player.x;
    int y = client->player.y;

    if (nb_players_incantation(client, elevation) >= elev[l][0]
            && client->server->map[y][x][1] >= elev[l][1]
            && client->server->map[y][x][2] >= elev[l][2]
            && client->server->map[y][x][3] >= elev[l][3]
            && client->server->map[y][x][4] >= elev[l][4]
            && client->server->map[y][x][5] >= elev[l][5]
            && client->server->map[y][x][6] >= elev[l][6]) {
        return 1;
    }
    return 0;
}

static int can_elevate(zappy_client_t *client, int elevation)
{
    return client->player.lvl < 8 && meet_conditions(client, elevation);
}

int can_elevation_start(zappy_client_t *client)
{
    if (already_incantating(client) || !can_elevate(client, 0)) {
        dprintf(client->sockfd, "ko\n");
        return 0;
    }
    for (int i = 0; i < ZAPPY_SERVER_MAX_CLIENTS; ++i) {
        if (player_equals_incantation(client, &client->server->clients[i], 0)) {
            client->server->clients[i].player.elevation = 1;
            add_player_command(&client->server->clients[i]
                    , &client->server->incantation_wait, NULL);
        }
    }
    return 1;
}

void player_incantation(zappy_client_t *client, char *)
{
    if (!can_elevate(client, 1)) {
        dprintf(client->sockfd, "ko\n");
        return;
    }
    for (int i = 0; i < ZAPPY_SERVER_MAX_CLIENTS; ++i) {
        if (player_equals_incantation(client, &client->server->clients[i], 1)) {
            ++client->server->clients[i].player.lvl;
            client->server->clients[i].player.elevation = 0;
        }
    }
    dprintf(client->sockfd, "ok\n");
}

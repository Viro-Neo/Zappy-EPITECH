/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** player.c
*/

#include <stdio.h>
#include <string.h>
#include "zappy_server.h"

zappy_player_t *get_player_by_id(zappy_server_t *server, int id)
{
    zappy_client_t *client = NULL;

    for (int i = 0; i < ZAPPY_SERVER_MAX_CLIENTS; ++i) {
        client = &server->clients[i];
        if (client->player.id != 0 && client->player.id == id) {
            return &client->player;
        }
    }
    return NULL;
}

void add_player_command(zappy_client_t* client, zappy_pcmd_t *pcmd, char *data)
{
    int i = 0;
    int data_len = strlen(data);

    data_len = (data_len > 9) ? 9 : data_len;
    for (; i < 10; ++i) {
        if (client->player.cmds[i].pcmd == NULL) {
            client->player.cmds[i].pcmd = pcmd;
            memset(client->player.cmds[i].data, 0, 10);
            memcpy(client->player.cmds[i].data, data, data_len);
            break;
        }
    }
    if (i == 0) {
        client->player.cmd_start = client->server->now;
    }
}

void kill_player(zappy_client_t *client)
{
    if (client->player.id != 0) {
        if (!client->sockclose) {
            dprintf(client->sockfd, "dead\n");
        }
        memset(&client->player, 0, sizeof(client->player));
    }
}

/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** player.c
*/

#include <string.h>
#include <time.h>
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
    if (strcmp(pcmd->name, "Connect_nbr") == 0) {
        pcmd->func(client, data);
        return;
    }
    for (int i = 0; i < 10; ++i) {
        if (client->player.cmds[i].pcmd == NULL) {
            client->player.cmds[i].start = client->server->curr_time;
            client->player.cmds[i].pcmd = pcmd;
            client->player.cmds[i].data = data;
            return;
        }
    }
}

struct timespec get_end_time(zappy_server_t* server, zappy_player_cmd_t *cmd)
{
    struct timespec ts = cmd->start;
    double duration = (double)cmd->pcmd->time_limit / server->freq;
    time_t sec = duration;

    ts.tv_sec += sec;
    ts.tv_nsec += (duration - sec) * 1000000000;
    if (ts.tv_nsec >= 1000000000) {
        ++ts.tv_sec;
        ts.tv_nsec -= 1000000000;
    }
    return ts;
}

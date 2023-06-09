/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** game_loop.c
*/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "zappy_server.h"

static void process_player_commands(zappy_client_t *client)
{
    zappy_player_cmd_t *cmd = &client->player.cmds[0];
    unsigned long cmd_len = sizeof(zappy_player_cmd_t);
    struct timespec curr = client->server->curr_time;
    struct timespec end;

    if (cmd->pcmd != NULL) {
        end = get_end_time(client->server, cmd);
        if (curr.tv_sec >= end.tv_sec && curr.tv_nsec >= end.tv_nsec) {
            cmd->pcmd->func(client, cmd->data);
            memcpy(client->player.cmds, &client->player.cmds[1], cmd_len * 9);
            memset(&client->player.cmds[9], 0, cmd_len);
        }
    }
}

static void players_commands(zappy_server_t *server)
{
    zappy_client_t *client = NULL;

    for (int i = 0; i < ZAPPY_SERVER_MAX_CLIENTS; ++i) {
        client = &server->clients[i];
        if (!(client->sockfd < 0) && client->player.id != 0) {
            process_player_commands(&server->clients[i]);
        }
    }
}

void game_loop(zappy_server_t *server)
{
    srand(time(NULL));
    spawn_resources(server);
    while (1) {
        if (clock_gettime(CLOCK_REALTIME, &server->curr_time) != 0) {
            dprintf(2, "An internal error has occurred: %s\n", strerror(errno));
            break;
        }
        if (!listen_sockets(server)) {
            break;
        }
        players_commands(server);
        usleep(50000);
    }
}

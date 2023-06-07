/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** client_read.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "zappy_server.h"

static void player_join_team(zappy_client_t *client, zappy_team_t *team)
{
    static int player_id = 0;
    zappy_server_t *server = client->server;

    --team->slot;
    client->player.id = ++player_id;
    client->player.x = rand() % server->width;
    client->player.y = rand() % server->height;
    client->player.rot = rand() % 4;
    client->player.team = team;
    dprintf(client->sockfd, "%d\n", team->slot);
    dprintf(client->sockfd, "%d %d\n", server->width, server->height);
}

static void register_team(zappy_client_t* client, char* data)
{
    zappy_team_t *team = get_team(client->server, data);

    if (team != NULL && team->slot > 0) {
        player_join_team(client, team);
    } else if (strcmp(data, "GRAPHIC") == 0) {
        client->graphic = 1;
        graphical_msz(client, NULL);
        graphical_sgt(client, NULL);
        graphical_mct(client, NULL);
        graphical_tna(client, NULL);
    } else {
        dprintf(client->sockfd, "ko\n");
    }
}

static void parse_cmd(zappy_client_t* client, char* data)
{
    if (client->graphic) {
        commands_graphical(client, data);
    } else if (client->player.id != 0) {
        commands_player(client, data);
    } else {
        register_team(client, data);
    }
}

static void parse_read(zappy_client_t* client)
{
    static char* sep = "\n";
    char* buffer = client->buffer;
    char* pos = NULL;

    while ((pos = strstr(buffer, sep)) != NULL) {
        pos[0] = '\0';
        if (strlen(buffer) > 0) {
            parse_cmd(client, buffer);
        }
        buffer = pos + strlen(sep);
    }
    client->pending = strlen(buffer);
    if (client->pending > 0) {
        memcpy(client->buffer, buffer, client->pending);
    }
}

void read_client(zappy_client_t* client)
{
    ssize_t bytesread = 0;
    size_t bytes = ZAPPY_SERVER_BUFFER_SIZE - client->pending - 1;

    bytesread = read(client->sockfd, client->buffer + client->pending, bytes);
    if (bytesread > 0) {
        client->buffer[bytesread + client->pending] = '\0';
        parse_read(client);
    } else {
        remove_client(client);
    }
}

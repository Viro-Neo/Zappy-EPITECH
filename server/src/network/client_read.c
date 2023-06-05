/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** client_read.c
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "zappy_server.h"

static void parse_cmd(zappy_client_t* client, char* data)
{
    (void)client;
    (void)data;
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
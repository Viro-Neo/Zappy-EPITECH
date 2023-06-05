/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** commands_parse.c
*/

#include <string.h>
#include "zappy_server.h"

void commands_graphical(zappy_client_t* client, char* data)
{
    zappy_commands_t *command = NULL;

    for (int i = 0; i < ZAPPY_SERVER_GRAPHICAL_COMMANDS_COUNT; ++i) {
        command = &client->server->graphical_commands[i];
        if (strcmp(command->name, data) == 0) {
            command->func(client, data);
            break;
        }
    }
}

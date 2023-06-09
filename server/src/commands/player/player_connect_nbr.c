/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** player_connect_nbr.c
*/

#include <stdio.h>
#include "zappy_server.h"

void player_connect_nbr(zappy_client_t *client, char *)
{
    dprintf(client->sockfd, "%d\n", client->player.team->slot);
}

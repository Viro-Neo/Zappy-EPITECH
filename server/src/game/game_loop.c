/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** game_loop.c
*/

#include <unistd.h>
#include "zappy_server.h"

void game_loop(zappy_server_t *server)
{
    while (listen_sockets(server)) {
        usleep(50000);
    }
}

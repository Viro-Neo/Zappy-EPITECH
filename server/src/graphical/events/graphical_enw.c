/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** graphical_enw.c
*/

#include "zappy_server.h"

void graphical_enw(zappy_server_t *server, zappy_player_t *player
, zappy_egg_t *egg)
{
    graphical_write(server, "enw %d %d %u %u\n"
            , egg->id
            , player->id
            , player->x
            , player->y);
}

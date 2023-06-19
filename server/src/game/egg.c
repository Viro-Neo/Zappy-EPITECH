/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** egg.c
*/

#include <stdlib.h>
#include "zappy_server.h"

int spawn_eggs(zappy_server_t *server, zappy_team_t *team, int nb)
{
    zappy_egg_t **egg = &team->eggs;

    while (*egg != NULL) {
        egg = &(*egg)->next;
    }
    while (nb > 0) {
        *egg = malloc(sizeof(zappy_egg_t));
        if (*egg == NULL) {
            return 0;
        }
        (*egg)->x = rand() % server->width;
        (*egg)->y = rand() % server->height;
        (*egg)->next = NULL;
        egg = &(*egg)->next;
        ++team->slot;
        --nb;
    }
    return 1;
}

zappy_egg_t* get_random_egg(zappy_team_t *team)
{
    zappy_egg_t **egg = &team->eggs;
    zappy_egg_t *res = NULL;
    int i = 0;

    if (team->slot > 0) {
        i = rand() % team->slot;
        while (i > 0) {
            egg = &(*egg)->next;
            --i;
        }
        res = *egg;
        *egg = (*egg)->next;
        --team->slot;
    }
    return res;
}

void free_eggs(zappy_team_t *team)
{
    zappy_egg_t *next_egg = team->eggs;
    zappy_egg_t *egg = NULL;

    while (next_egg != NULL) {
        egg = next_egg;
        next_egg = egg->next;
        free(egg);
    }
}

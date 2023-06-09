/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** teams.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zappy_server.h"

static zappy_team_t *create_team(char *team_name)
{
    zappy_team_t *team = malloc(sizeof(zappy_team_t));
    char *name = strdup(team_name);

    if (team != NULL && name != NULL) {
        team->name = name;
        team->next = NULL;
        return team;
    }
    fprintf(stderr, "An internal error has occurred: Unable to create a team");
    free(team);
    free(name);
    return NULL;
}

static int team_names_index(char *argv[])
{
    int argc = 1;

    for (; argv[argc] != NULL; ++argc) {
        if (strcmp(argv[argc], "-n") == 0) {
            return argc + 1;
        }
    }
    return argc;
}

int parse_team_names(char *argv[], zappy_server_t *server)
{
    zappy_team_t **next_team = &server->teams;
    int i = team_names_index(argv);

    for (; (argv[i] != NULL && argv[i][0] != '-'); ++i) {
        *next_team = create_team(argv[i]);
        if (*next_team == NULL) {
            return 0;
        }
        next_team = &(*next_team)->next;
    }
    return 1;
}

int get_num_teams(zappy_server_t *server)
{
    zappy_team_t **next_team = &server->teams;
    int num = 0;

    while (*next_team != NULL) {
        ++num;
        next_team = &(*next_team)->next;
    }
    return num;
}

void free_teams(zappy_server_t *server)
{
    zappy_team_t *next_team = server->teams;
    zappy_team_t *team = NULL;

    while (next_team != NULL) {
        team = next_team;
        next_team = team->next;
        free(team->name);
        free(team);
    }
}

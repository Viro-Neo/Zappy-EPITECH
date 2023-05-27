/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** zappy_server.h
*/

#ifndef _ZAPPY_SERVER_H_
    #define _ZAPPY_SERVER_H_

typedef struct zappy_team_s {
    char *name;
    struct zappy_team_s *next;
} zappy_team_t;

typedef struct zappy_server_s {
    int port;
    int width;
    int height;
    zappy_team_t *teams;
    int clientsNb;
    int freq;
} zappy_server_t;

int parse_args(int argc, char *argv[], zappy_server_t *server);

int check_help(int argc, char *argv[]);

int parse_team_names(char *argv[], zappy_server_t *server);
int get_num_teams(zappy_server_t *server);
void free_teams(zappy_server_t *server);

#endif

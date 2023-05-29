/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** zappy_server.h
*/

#ifndef _ZAPPY_SERVER_H_
    #define _ZAPPY_SERVER_H_

    #define ZAPPY_SERVER_MAX_CLIENTS 100
    #define ZAPPY_SERVER_BUFFER_SIZE 1024

    #include <sys/types.h>

typedef struct zappy_server_s zappy_server_t;

typedef struct zappy_client_s {
    int sockfd;
    char buffer[ZAPPY_SERVER_BUFFER_SIZE];
    ssize_t pending;
    zappy_server_t *server;
} zappy_client_t;

typedef struct zappy_team_s {
    char *name;
    struct zappy_team_s *next;
} zappy_team_t;

struct zappy_server_s {
    int port;
    int width;
    int height;
    zappy_team_t *teams;
    int clientsNb;
    int freq;
    int sockfd;
    zappy_client_t clients[ZAPPY_SERVER_MAX_CLIENTS];
};

void game_loop(zappy_server_t *server);

int start_server(zappy_server_t *server);
void stop_server(zappy_server_t *server);

int parse_args(int argc, char *argv[], zappy_server_t *server);

int check_help(int argc, char *argv[]);

int parse_team_names(char *argv[], zappy_server_t *server);
int get_num_teams(zappy_server_t *server);
void free_teams(zappy_server_t *server);

#endif

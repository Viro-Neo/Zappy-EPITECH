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
    #define ZAPPY_SERVER_GRAPHICAL_COMMANDS_COUNT 8
    #define ZAPPY_SERVER_PLAYER_COMMANDS_COUNT 0

    #include <arpa/inet.h>
    #include <sys/select.h>
    #include <sys/types.h>

typedef struct zappy_server_s zappy_server_t;

typedef struct zappy_team_s {
    char *name;
    int slot;
    struct zappy_team_s *next;
} zappy_team_t;

typedef struct zappy_player_s {
    int id;
    int x;
    int y;
    int rot;
    int lvl;
    int inventory[7];
    zappy_team_t *team;
} zappy_player_t;

typedef struct zappy_client_s {
    int sockfd;
    char address[INET_ADDRSTRLEN];
    uint16_t port;
    char buffer[ZAPPY_SERVER_BUFFER_SIZE];
    ssize_t pending;
    zappy_player_t player;
    int graphic;
    zappy_server_t *server;
} zappy_client_t;

typedef struct zappy_commands_s {
    char name[4];
    void (*func)(zappy_client_t *, char *);
} zappy_commands_t;

struct zappy_server_s {
    int port;
    int width;
    int height;
    zappy_team_t *teams;
    int clientsNb;
    int freq;
    int sockfd;
    zappy_client_t clients[ZAPPY_SERVER_MAX_CLIENTS];
    zappy_commands_t graphical_commands[ZAPPY_SERVER_GRAPHICAL_COMMANDS_COUNT];
    zappy_commands_t player_commands[ZAPPY_SERVER_PLAYER_COMMANDS_COUNT];
    int map[30][30][7];
};

typedef struct zappy_opt_s {
    int c;
    int (*func)(int, int, int);
} zappy_opt_t;

int tile_content(zappy_client_t *client, int x, int y);
void graphical_bct(zappy_client_t *client, char *data);
void graphical_mct(zappy_client_t *client, char *data);
void graphical_msz(zappy_client_t *client, char *data);
void graphical_plv(zappy_client_t *client, char *data);
void graphical_ppo(zappy_client_t *client, char *data);
void graphical_sgt(zappy_client_t *client, char *data);
void graphical_sst(zappy_client_t *client, char *data);
void graphical_tna(zappy_client_t *client, char *data);

void commands_graphical(zappy_client_t* client, char* data);
void commands_player(zappy_client_t* client, char* data);

void game_loop(zappy_server_t *server);

zappy_player_t *get_player_by_id(zappy_server_t *server, int id);

void spawn_resources(zappy_server_t *server);

void read_client(zappy_client_t *client);

void add_client(zappy_server_t *server, zappy_client_t *client, int sockfd
, struct sockaddr_in *addr_in);
void remove_client(zappy_client_t *client);

int listen_sockets(zappy_server_t *server);

int read_select(zappy_server_t *server, fd_set *readfds);

int start_server(zappy_server_t *server);
void stop_server(zappy_server_t *server);

int check_opt_p(int is_number, int num, int c);
int check_opt_xy(int is_number, int num, int c);
int check_opt_c(int is_number, int num, int c);
int check_opt_f(int is_number, int num, int c);

int parse_args(int argc, char *argv[], zappy_server_t *server);

int check_help(int argc, char *argv[]);

int parse_team_names(char *argv[], zappy_server_t *server);
zappy_team_t *get_team(zappy_server_t *server, char *team_name);
void free_teams(zappy_server_t *server);

int is_number(char* str);

#endif

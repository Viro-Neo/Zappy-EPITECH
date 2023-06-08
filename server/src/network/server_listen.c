/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** server_listen.c
*/

#include <stddef.h>
#include <sys/select.h>
#include "zappy_server.h"

static void set_client_fds(zappy_server_t *server, fd_set *readfds, int *maxfd)
{
    static zappy_client_t *client = NULL;

    for (int i = 0; i < ZAPPY_SERVER_MAX_CLIENTS; ++i) {
        client = &server->clients[i];
        if (!(client->sockfd < 0)) {
            FD_SET(client->sockfd, readfds);
            *maxfd = (client->sockfd > *maxfd) ? client->sockfd : *maxfd;
        }
    }
}

static void init_select(zappy_server_t *server, fd_set *readfds, int *maxfd)
{
    FD_ZERO(readfds);
    FD_SET(server->sockfd, readfds);
    *maxfd = server->sockfd;
    if (server->signalfd != -1) {
        FD_SET(server->signalfd, readfds);
        if (server->signalfd > *maxfd) {
            *maxfd = server->signalfd;
        }
    }
    set_client_fds(server, readfds, maxfd);
}

static void next_timeout(zappy_server_t *server, struct timeval **next_timeout)
{
    static struct timeval timeout;

    (void)server;
    timeout.tv_sec = 0;
    timeout.tv_usec = 0;
    *next_timeout = &timeout;
}

int listen_sockets(zappy_server_t *server)
{
    static fd_set readfds;
    static int maxfd = 0;
    static int fds = 0;
    struct timeval *timeout = NULL;

    init_select(server, &readfds, &maxfd);
    next_timeout(server, &timeout);
    fds = select(maxfd + 1, &readfds, NULL, NULL, timeout);
    if (fds > 0) {
        return read_select(server, &readfds);
    }
    return !(fds < 0);
}

/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** server_listen.c
*/

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/select.h>
#include <time.h>
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

static void find_timeout(zappy_client_t *client, struct timeval **timeout_ptr
, struct timespec *curr)
{
    static struct timespec end;
    static struct timeval remaining;
    static struct timeval timeout;

    if (client->player.id != 0 && client->player.cmds[0].pcmd != NULL) {
        end = get_end_time(client);
        remaining.tv_sec = end.tv_sec - curr->tv_sec;
        remaining.tv_usec = (end.tv_nsec - curr->tv_nsec) / 1000;
        if (remaining.tv_usec < 0) {
            --remaining.tv_sec;
            remaining.tv_usec += 1000000;
        }
        if (*timeout_ptr == NULL || (remaining.tv_sec < timeout.tv_sec
                && remaining.tv_usec < timeout.tv_usec)) {
            timeout.tv_sec = remaining.tv_sec;
            timeout.tv_usec = remaining.tv_usec;
            *timeout_ptr = &timeout;
        }
    }
}

static void next_timeout(zappy_server_t *server, struct timeval **timeout_ptr)
{
    static struct timespec curr;
    static zappy_client_t *client = NULL;

    *timeout_ptr = NULL;
    if (clock_gettime(CLOCK_REALTIME, &curr) != 0) {
        dprintf(2, "An internal error has occurred: %s\n", strerror(errno));
        return;
    }
    for (int i = 0; i < ZAPPY_SERVER_MAX_CLIENTS; ++i) {
        client = &server->clients[i];
        if (!(client->sockfd < 0)) {
            find_timeout(client, timeout_ptr, &curr);
        }
    }
}

int listen_sockets(zappy_server_t *server)
{
    static fd_set readfds;
    static int maxfd = 0;
    static int fds = 0;
    static struct timeval *timeout_ptr = NULL;

    init_select(server, &readfds, &maxfd);
    next_timeout(server, &timeout_ptr);
    fds = select(maxfd + 1, &readfds, NULL, NULL, timeout_ptr);
    if (fds > 0) {
        return read_select(server, &readfds);
    }
    return !(fds < 0);
}

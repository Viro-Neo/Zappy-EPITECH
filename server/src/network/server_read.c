/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** server_read.c
*/

#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>
#include "zappy_server.h"

static void accept_client(zappy_server_t *server)
{
    struct sockaddr_in addr_in;
    socklen_t addrlen = sizeof(addr_in);
    int sockfd = accept(server->sockfd, (struct sockaddr*)&addr_in, &addrlen);

    if (sockfd < 0) {
        return;
    }
    for (int i = 0; i < ZAPPY_SERVER_MAX_CLIENTS; ++i) {
        if (server->clients[i].sockfd < 0) {
            add_client(server, &server->clients[i], sockfd, &addr_in);
            return;
        }
    }
    close(sockfd);
    printf("Server is full.\n");
}

void read_select(zappy_server_t *server, fd_set *readfds)
{
    if (FD_ISSET(server->sockfd, readfds)) {
        accept_client(server);
    }
}

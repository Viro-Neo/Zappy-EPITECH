/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** args.c
*/

#include <ctype.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include "zappy_server.h"

static void set_opt(zappy_server_t *server, int c, int num)
{
    if (c == 'p')
        server->port = num;
    if (c == 'x')
        server->width = num;
    if (c == 'y')
        server->height = num;
    if (c == 'c')
        server->clientsNb = num;
    if (c == 'f')
        server->freq = num;
}

static int is_number(char* str)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

static int check_arg(zappy_server_t *server, int c)
{
    int res = is_number(optarg);
    int num = 0;

    if (res) {
        num = atoi(optarg);
    }
    if (!res || !(num > 0)) {
        fprintf(stderr, "Argument -%c must be a positive number\n", c);
        return 0;
    }
    set_opt(server, c, num);
    return 1;
}

int parse_args(int argc, char *argv[], zappy_server_t *server)
{
    int c = 0;

    opterr = 0;
    while ((c = getopt(argc, argv, "p:x:y:nc:f:")) != -1) {
        if (c == '?') {
            fprintf(stderr, "Invalid argument: -%c\n", optopt);
            return 0;
        }
        if (optarg && !check_arg(server, c)) {
            return 0;
        }
    }
    return parse_team_names(argv, server);
}

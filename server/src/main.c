/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** main.c
*/

#include "zappy_server.h"

int main(int argc, char *argv[])
{
    zappy_server_t server;

    if (!parse_args(argc, argv, &server)) {
        return 84;
    }
    return 0;
}

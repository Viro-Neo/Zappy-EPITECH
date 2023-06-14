/*
** EPITECH PROJECT, 2023
** server
** File description:
** look
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zappy_server.h"

char *food_message(int *title, char * message)
{
    char food[11] = "";
    if (title[0] > 0){
        printf("food\n");
        strcat(food, "food ");
    }
    strcat(message, food);
    return message;
}

char *deraumere_message(int *title, char * message)
{
    char deraumere[11] = "";
    if (title[2] > 0){
        printf("deraumere\n");
        strcat(deraumere, "deraumere ");
    }
    strcat(message, deraumere);
    return message;
}

char *linemate_message(int *title, char * message)
{
    char linemate[11] = "";
    if (title[1] > 0){
        printf("linemate\n");
        strcat(linemate, "linemate ");
    }
    strcat(message, linemate);
    return message;
}

char *sibur_message(int *title, char * message)
{
    char sibur[11] = "";
    if (title[3] > 0){
        printf("sibur\n");
        strcat(sibur, "sibur ");
    }
    strcat(message, sibur);
    return message;
}

char *mendiane_message(int *title, char * message)
{
    char mendiane[11] = "";
    if (title[4] > 0){
        printf("mendiane\n");
        strcat(mendiane, "mendiane ");
    }
    strcat(message, mendiane);
    return message;
}

char *phiras_message(int *title, char * message)
{
    char phiras[11] = "";
    if (title[5] > 0){
        printf("phiras\n");
        strcat(phiras, "phiras ");
    }
    strcat(message, phiras);
    return message;
}

char *thystame_message(int *title, char * message)
{
    char thystame[11] = "";
    if (title[6] > 0){
        printf("thystame\n");
        strcat(thystame, "thystame ");
    }
    strcat(message, thystame);
    return message;
}

char *parse_message(int *title, char *message)
{
    char ressource[100] = "";
    message = food_message(title, message);
    message = linemate_message(title, message);
    message = deraumere_message(title, message);
    message = sibur_message(title, message);
    message = mendiane_message(title, message);
    message = phiras_message(title, message);
    message = thystame_message(title, message);
    return message;
}

char *malloc_look(char *message)
{
    char *look = malloc(sizeof(char) * strlen(message));
    look = message;
    return look;
}

char *look(zappy_server_t *server, int x, int y)
{
    char *look;
    char message[5000] = "";
    int *title = NULL;
    int i;
    int nb = 3;
    strcat(message, "player ");
    for (int v = 0; v < 3; v++) {
        x = x + 1;
        y = y - 1;
        i = y;
        for (int b = 0; b < nb; b++) {
            title = server->map[x % server->width][i % server->height];
            strcat(message, ", ");
            parse_message(title, message);
            i = i + 1;
        }
        nb = nb + 2;
    }
    look = malloc_look(message);
    return look;
}

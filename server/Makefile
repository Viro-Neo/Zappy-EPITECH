##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-aurelien.duval
## File description:
## Makefile
##

NAME	=	../zappy_server

SRCS	=	src/commands/graphical/graphical_msz.c \
			src/commands/graphical/graphical_tna.c \
			src/commands/commands_parse.c \
			src/game/game_loop.c \
			src/network/client_read.c \
			src/network/client.c \
			src/network/server_listen.c \
			src/network/server_read.c \
			src/network/server.c \
			src/args_handling.c \
			src/args.c \
			src/help.c \
			src/main.c \
			src/teams.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -Iinclude

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re

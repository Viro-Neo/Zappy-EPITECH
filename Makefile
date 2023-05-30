##
## EPITECH PROJECT, 2021
## makefile infin_add
## File description:
## Makefile
##

SERVER_SRC	=	server_zappy/main.cpp	\

SERVER_OBJ     =       $(SERVER_SRC:.cpp=.o)

CFLAGS	=	-W -Wall -Wextra -g3

SERVER_NAME    =	zappy_server

AI_SRC = 	ai_zappy/main.cpp	\

AI_OBJ	=	$(AI_SRC:.cpp=.o)

AI_NAME    =	zappy_ai

GUI_NAME	=	zappy_gui

all: $(SERVER_NAME) $(AI_NAME)

$(AI_NAME): $(AI_OBJ)
	@g++ -o $(AI_NAME) $(AI_OBJ)
	@echo -e "\e[92;5m       ====Bien joué bg====      \e[0m"


$(SERVER_NAME): $(SERVER_OBJ)
	@g++ -o $(SERVER_NAME) $(SERVER_OBJ)
	@echo -e "\e[92;5m       ====Bien joué bg====      \e[0m"

$(GUI_NAME):
	@make -C ./gui_zappy/
	@echo -e "\e[92;5m       ====Bien joué bg====      \e[0m"

clean:
	rm -f $(SERVER_OBJ)
	rm -f $(AI_OBJ)
	make clean -C ./gui_zappy/
	rm -f *gcno

fclean: clean
	rm -f $(SERVER_NAME)
	rm -f $(AI_NAME)
	make fclean -C ./gui_zappy/
	rm -f *~
	rm -f *.o
	rm -rf vgcore.*

re:     fclean all

.PHONY:	clean fclean re all

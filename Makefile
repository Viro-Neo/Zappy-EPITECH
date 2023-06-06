##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-aurelien.duval
## File description:
## Makefile
##

SERVER_SRC	=	server_zappy/main.cpp	\

SERVER_OBJ     =       $(SERVER_SRC:.cpp=.o)

# zappy_ai:
#	make -C ai/

# zappy_gui:
#	make -C gui/

AI_NAME    =	zappy_ai

GUI_NAME	=	zappy_gui

all: $(SERVER_NAME) $(AI_NAME) $(GUI_NAME)

$(AI_NAME): $(AI_OBJ)
	@make -C ./client_zappy/
	@echo -e "\e[92;5m       ====Bien joué bg====      \e[0m"


$(SERVER_NAME): $(SERVER_OBJ)
	@g++ -o $(SERVER_NAME) $(SERVER_OBJ)
	@echo -e "\e[92;5m       ====Bien joué bg====      \e[0m"

$(GUI_NAME):
	@make -C ./gui_zappy/
	@echo -e "\e[92;5m       ====Bien joué bg====      \e[0m"

clean:
	rm -f $(SERVER_OBJ)
	make clean -C ./gui_zappy/
	rm -f *gcno

fclean: clean
	rm -f $(SERVER_NAME)
	make fclean -C ./client_zappy/
	make fclean -C ./gui_zappy/
	rm -f *~
	rm -f *.o
	rm -rf vgcore.*

re:	fclean all

.PHONY:	clean fclean re all

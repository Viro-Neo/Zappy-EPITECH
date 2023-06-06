##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-aurelien.duval
## File description:
## Makefile
##

all:	zappy_ai zappy_gui zappy_server

zappy_ai:
#	make -C ai/

zappy_gui:
#	make -C gui/

zappy_server:
	make -C server/

clean:
#	make clean -C ai/
#	make clean -C gui/
	make clean -C server/

fclean:	clean
#	make fclean -C ai/
#	make fclean -C gui/
	make fclean -C server/

re:	fclean all

.PHONY: all zappy_ai zappy_gui zappy_server clean fclean re

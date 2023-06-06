##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-aurelien.duval
## File description:
## Makefile
##

CC =	g++

SRCNAME =	main	\
			Gui
SRC =	$(addprefix src/, $(addsuffix .cpp, $(SRCNAME)))
OBJ =	$(SRC:.cpp=.o)

CFLAGS	=	-W -Wall -Wextra
CPPFLAGS +=	-I./include

NAME =	zappy_gui

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ)
	@mv $(NAME) ../

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f ../$(NAME)

re: fclean all

.PHONY: all clean fclean re

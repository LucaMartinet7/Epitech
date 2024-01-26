##
## EPITECH PROJECT, 2022
## B-CPE-110-PAR-1-2-BSQ-luca.martinet
## File description:
## Makefile
##

CC 	?= 	gcc

SRC 	=		main.c				\
				src/helper.c		\
				src/sbml.c			\
				requirement.c		\
				src/str_word_arr.c	\
				src/check.c			\
				src/open_file.c		\
				src/my_strlen.c		\
				src/parsing.c		\

OBJ     = 		$(SRC:.c=.o)

NAME	=		 SBMLparser

DEBUG = -pedantic -g3

CFLAGS 	=	-W -Wall -Wextra

all:	$(NAME)

$(NAME): $(OBJ)
		$(CC) -o $(NAME) $(OBJ)
		@echo -e "\033[1;32mFinish Compiling\033[0m"

debug:
		$(CC) -o $(NAME) $(SRC) $(CFLAGS) $(DEBUG)
		@echo -e "\033[1;32mFinish Compiling DEBUG\033[0m"

clean:
		rm -f $(OBJ)
		rm -f vgcore.*

fclean: clean
		rm -f $(NAME)
		rm -f vgcore.*
		@echo -e "\033[1;31mfclean done\033[0m"

re: fclean all

.PHONY: all debug clean fclean re

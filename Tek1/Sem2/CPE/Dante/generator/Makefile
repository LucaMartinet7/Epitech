##
## EPITECH PROJECT, 2022
## B-CPE-110-PAR-1-2-BSQ-luca.martinet
## File description:
## Makefile
##

CC 	= 	gcc

SRC 	=		main.c					\
				perfect.c				\
				imperfect.c				\

OBJ     = 		$(SRC:.c=.o)

NAME	=		 generator

DEBUG = 	-pedantic -g3

CFLAGS 	=	-W -Wall -Wextra

all:	$(NAME)

$(NAME): $(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS) $(DEBUG)
		@echo -e "\033[1;32mgenerator make done\033[0m"
clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		@echo -e "\033[1;31mfclean generator done\033[0m"

re: fclean all

##
## EPITECH PROJECT, 2023
## pain_au_chocolat
## File description:
## Makefile
##

CC 	= 	gcc

SRC 	=		src/main.c

OBJ     = 		$(SRC:.c=.o)

NAME	=		 test

CFLAGS 	=	-W -Wall -Wextra -pedantic -g3

all:	$(NAME)

$(NAME): $(OBJ)
		gcc -o $(NAME) $(OBJ)
		@echo -e "\033[1;32mOe Oe Oe\033[0m"

tests_run:
	make -C tests/

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		make fclean -C ./tests
		@echo -e "\033[1;31mfclean done\033[0m"

re: fclean all

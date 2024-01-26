##
## EPITECH PROJECT, 2022
## B-CPE-110-PAR-1-2-BSQ-luca.martinet
## File description:
## Makefile
##

CC 	?= 	gcc

SRC 	=		main.c					\
				src/palin.c				\
				src/utils.c				\
				src/validation.c		\
				src/utils2.c			\

OBJ     = 		$(SRC:.c=.o)

NAME	=		 palindrome

DEBUG = -pedantic -g3

TESTS = -lcriterion --coverage

CFLAGS 	=	-W -Wall -Wextra

all:	$(NAME)

$(NAME): $(OBJ)
		$(CC) -o $(NAME) $(OBJ)
		@echo -e "\033[1;32mFinish Compiling\033[0m"

debug:
		$(CC) -o $(NAME) $(SRC) $(CFLAGS) $(DEBUG)
		@echo -e "\033[1;32mFinish Compiling DEBUG\033[0m"

unit_tests:
		$(CC) -o $(NAME) $(SRC) $(TESTS)
		@echo -e "\033[1;32mFinish Compiling unit_tests\033[0m"

clean:
		rm -f $(OBJ)
		rm -f vgcore.*

fclean: clean
		rm -f $(NAME)
		rm -f vgcore.*
		rm -f *.gcda
		rm -f *.gcno
		rm -f *.gcda
		@echo -e "\033[1;31mfclean done\033[0m"

re: fclean all

.PHONY: all debug clean fclean re

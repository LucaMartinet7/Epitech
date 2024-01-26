##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

CC      =       gcc

SRC     =               src/fibonacci_checker.c		\

OBJ     =               $(SRC:.c=.o)

NAME    =                fibonacci_checker

CFLAGS  =       -W -Wall -Wextra -pedantic -g3

all:    $(NAME)

$(NAME): $(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

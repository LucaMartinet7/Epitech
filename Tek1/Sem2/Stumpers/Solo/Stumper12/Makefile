##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

CC      =       gcc

SRC     =               src/hidenp.c		\
			src/my_strlen.c

OBJ     =               $(SRC:.c=.o)

NAME    =                hidenp

CFLAGS  =       -W -Wall -Wextra -pedantic -g3

all:    $(NAME)

$(NAME): $(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

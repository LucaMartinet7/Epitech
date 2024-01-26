##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

CC      =       gcc

SRC     =               src/palindrome.c 	\
			src/my_strlen.c	 	\
			src/my_strlowcase.c

OBJ     =               $(SRC:.c=.o)

NAME    =                palindrome

CFLAGS  =       -W -Wall -Wextra -pedantic -g3

all:    $(NAME)

$(NAME): $(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

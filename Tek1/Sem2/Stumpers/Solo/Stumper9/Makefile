##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

CC      =       gcc

SRC     =               src/gpa_calculator.c 		\
			src/my_strlen.c	 		\
			src/my_str_to_word_array.c	\
			src/my_putchar.c		\

OBJ     =               $(SRC:.c=.o)

NAME    =                gpa_calculator

CFLAGS  =       -W -Wall -Wextra -pedantic -g3

all:    $(NAME)

$(NAME): $(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

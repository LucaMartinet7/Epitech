##
## EPITECH PROJECT, 2023
## B-AIA-200-PAR-2-2-n4s-luca.martinet
## File description:
## Makefile
##

SRC		=	src/main.c				\
			lib/my/my_putchar.c		\
			lib/my/my_putstr.c		\
			src/str_to_word_array.c	\
			src/check_finish.c		\

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-W -Wall -Wextra

CC		=	gcc

NAME		=	ai

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean: 	clean
		rm -f $(NAME)

re:		fclean all

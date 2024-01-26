##
## EPITECH PROJECT, 2022
## B-MUL-100-PAR-1-2-myhunter-luca.martinet
## File description:
## Makefile
##

NAME	=		my_hunter

CFLAGS	=		-W -Wall -Wextra

SRC		=		src/my_hunter.c							\
				src/main.c								\
				src/game.c								\
				src/desc.c								\
				lib/my/my_printf/my_printf.c			\
				lib/my/my_put_nbr.c						\
				lib/my/my_putchar.c						\
				lib/my/my_putstr.c						\
				lib/my/my_revstr.c						\
				lib/my/my_strlen.c						\
				lib/my/my_printf/flags/int_to_oct.c		\
				lib/my/my_printf/flags/int_to_bin.c		\
				lib/my/my_printf/flags/my_put_u.c		\
				lib/my/my_getnbr.c						\
				lib/my/my_printf/flags/my_put_x_lower.c \
				lib/my/my_printf/flags/my_put_x_upper.c	\

OBJ		=		$(SRC:.c=.o)

CSFML	=		-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:	$(OBJ)
		gcc $(OBJ) -o $(NAME) -I../includes $(CFLAGS) $(CSFML)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re: fclean all

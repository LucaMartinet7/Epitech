##
## EPITECH PROJECT, 2022
## B-CPE-110-PAR-1-2-antman-luca.martinet
## File description:
## Makefile
##

NAME	=	antman

SRC		=	src/main.c			\
			src/countwords.c	\

INCLUDE	=	-Iinclude -Lprintf/ -lmy

CFLAGS	=	-W -Wall -Wextra

all:
		make -C printf/
		gcc -o $(NAME) $(SRC) $(INCLUDE) $(CFLAGS)

clean:
		make clean -C printf/
		rm -f $(NAME)

fclean:	clean
		make fclean -C printf/

re:	fclean	all

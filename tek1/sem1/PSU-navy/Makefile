##
## EPITECH PROJECT, 2022
## B-PSU-100-PAR-1-2-navy-noe.kurata
## File description:
## Makefile
##

SRC		=	src/main.c	\

NAME	=	navy

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

re:		fclean	all
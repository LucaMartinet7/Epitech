##
## EPITECH PROJECT, 2022
## make file
## File description:
## make file
##

CC		=	gcc

MAIN		=	rush3.c

SRC		=	lib/my/main.c	\
			lib/my/my_strlen.c	\
			lib/my/my_putstr.c	\
			lib/my/my_putchar.c	\
			lib/my/my_put_nbr.c	\

UT_SRC		=	test/test.c

UT_NAME		=	unit_tests

NAME 	=	rush3

OBJ	=	$(SRC:.c=.o)

NAMELIB	=	libmy.a

NAMEMY	=	my.h


all:	$(OBJ)
	ar rc $(NAMELIB)	$(OBJ)
	cp $(NAMELIB) lib
	$(CC) -o $(NAME) $(MAIN) -I include -L lib -lmy
clean:
	rm -f $(OBJ)
	rm -f *~

fclean:	clean
	rm -f $(NAME)

re:	fclean all

tests_run:
	$(CC) -o $(UT_NAME) -l include/ --coverage $(SRC) $(UT_SRC) -lcriterion
	$(UT_NAME)

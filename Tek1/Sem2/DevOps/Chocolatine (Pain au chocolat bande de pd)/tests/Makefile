##
## EPITECH PROJECT, 2023
## pain_au_chocolat
## File description:
## Makefile
##

CC      	=	gcc

SRC     	=	test.c

OBJ			=	$(SRC:.c=.o)

NAME		=	unit_tests

CFLAGS		=	--coverage

LDLIBS		=	-lcriterion


all:			fclean $(NAME)
				./$(NAME)

$(NAME):		$(OBJ)
				$(CC) -o $(NAME) $(OBJ) $(LDLIBS) $(CFLAGS) -lcriterion -lgcov

coverage:
	@gcovr

clean:
				rm -f $(OBJ)
				rm -f *.gc*

fclean: 		clean
				rm -f $(NAME)

re:				fclean all

##
## EPITECH PROJECT, 2024
## B-PDG-300-BAR-3-1-PDGD05-luca.martinet
## File description:
## Makefile
##

SRC		=	ex0.c  \
			ex1.c  \
			ex2.c  \
			ex3.c  \
			ex4.c  \
			ex5.c  \
			ex6.c  \
			ex7.c  \
			ex8.c  \
			ex9.c  \
			ex10.c \
			ex11.c \
			ex12.c \
			ex14.c \

NAME	=	libstring.a

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-std=gnu11 -Wall -Wextra -Werror

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re

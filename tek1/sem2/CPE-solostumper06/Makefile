##
## EPITECH PROJECT, 2022
## B-CPE-110-PAR-1-2-BSQ-luca.martinet
## File description:
## Makefile
##

CC 	= 	gcc

SRC 	=		luhn_validator.c		\
			my_strdup.c			\
			my_strlen.c			\
			my_putsrt.c			\
			my_putchar.c

OBJ     = 		$(SRC:.c=.o)

NAME	=		 luhn_validator

CFLAGS 	=	-W -Wall -Wextra -pedantic

all:	$(NAME)

$(NAME): $(OBJ)
		gcc -o $(NAME) $(OBJ)
clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

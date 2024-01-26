##
## EPITECH PROJECT, 2022
## B-CPE-110-PAR-1-2-BSQ-luca.martinet
## File description:
## Makefile
##

CC 	= 	gcc

SRC 	=		src/rostring.c			\
			src/my_strdup.c			\
			src/my_strlen.c			\
			src/my_putsrt.c			\
			src/my_putchar.c

OBJ     = 		$(SRC:.c=.o)

NAME	=		 rostring

CFLAGS 	=	-W -Wall -Wextra -pedantic

all:	$(NAME)

$(NAME): $(OBJ)
		gcc -o $(NAME) $(OBJ)
clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

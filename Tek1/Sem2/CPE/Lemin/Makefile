##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile
##

SRC	=		src/help.c				\
			src/remove_hashtag.c	\
			src/check_file_data.c	\
			src/check_file_clean.c	\
			src/check_file.c		\
			src/check_struct.c		\
			src/entry_point.c		\

OBJ	=	$(SRC:.c=.o)

LEM_MAIN	=	src/main.c	\

LEM_NAME	=	lem_in

NAME	=	libmy.a

CFLAGS	=	-Wall -Wextra -g3

CPPFLAGS =  -iquote include

all:	$(LEM_NAME)

$(LEM_NAME):	$(OBJ)
	make -C lib/my/
	gcc -o $(LEM_NAME) $(LEM_MAIN) $(OBJ) $(NAME) $(CFLAGS)

clean:
	make -C lib/my/ clean
	rm -f $(OBJ)
	rm -f *.gcda
	rm -f *.gcno

fclean: clean
	make -C lib/my/ fclean
	rm -f $(LEM_NAME)

re:	fclean all

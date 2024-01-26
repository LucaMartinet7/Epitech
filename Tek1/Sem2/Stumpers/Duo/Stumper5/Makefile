##
## EPITECH PROJECT, 2023
## generic
## File description:
## Makefile
##

CC  = gcc

SRC     =       src/main.c      \
		src/hangman.c	\
		src/open_file.c	\
		src/utilities.c	\

OBJ     =       $(SRC:.c=.o)

NAME    =       hangman

CPPFLAGS        =       -I ./include

CFLAGS  =       -Wall -Wextra -pedantic -g3

all:    $(NAME)

$(NAME):        $(OBJ)
				$(CC) -o $(NAME) $(SRC) $(CPPFLAGS) $(CFLAGS)

clean:
				$(RM) -f $(OBJ)
				$(RM) -f $(OBJ_UNIT)
				$(RM) -f *~
				$(RM) -f *.gcno
				$(RM) -f *.gcda
				$(RM) -f ./*~
				$(RM) -f ./*.gcno
				$(RM) -f ./*.gcda

fclean: clean
				$(RM) -f $(NAME)
				$(RM) -f $(NAME_UNIT)


re:     fclean all

.PHONY: all clean fclean re

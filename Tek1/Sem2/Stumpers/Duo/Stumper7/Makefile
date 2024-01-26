##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

CC  	?= 	gcc

SRC     =       src/main.c      \
                src/printer.c   \
                src/parser.c 	\
                src/sorter.c 	\

OBJ     =       $(SRC:.c=.o)

NAME    =       text_count

CPPFLAGS        =       -I ./include

CFLAGS  =       -Wall -Wextra

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

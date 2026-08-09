##
## EPITECH PROJECT, 2023
## generic
## File description:
## Makefile
##

CC  		= 	gcc

SRC     	=       src/main.c      		\
			src/fridge.c			\
			src/get_commands.c		\
			src/my_str_to_word_array.c		\
			src/my_str_to_word_array_pt2.c	\
			src/my_strlen.c

OBJ     	=       $(SRC:.c=.o)

NAME    	=       fridge

CPPFLAGS        =       -I ./include

DEBUG 		= 	-pedantic -g3

CFLAGS  	=       -Wall -Wextra -pedantic -g3

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

debug:
				$(CC) -o $(NAME) $(SRC) $(CPPFLAGS) $(CFLAGS) $(DEBUG)

re:     fclean all

.PHONY: all clean fclean re

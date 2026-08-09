##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## my_hunter
##

SRC	=	src/main.c				\
		src/the_game.c			\
		src/battle.c			\
		src/battle_2.c			\
		src/battle_3.c			\
		src/check_font.c		\
		src/extra_main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

CSFML	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

CFLAGS	=	-W -Wall -Wextra

all:	$(NAME)
$(NAME):	$(OBJ)
	make -C lib/my/
	gcc -o $(NAME) $(MAIN) $(OBJ) -I../include libmy.a $(CFLAGS) $(CSFML)

clean:
	make -C lib/my/ clean
	rm -f $(OBJ)
	rm -f *~

fclean:	clean
	make -C lib/my/ fclean
	rm -f $(NAME)

re:	fclean	all

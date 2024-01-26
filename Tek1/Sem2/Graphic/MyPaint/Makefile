##
## EPITECH PROJECT, 2022
## B-CPE-110-PAR-1-2-BSQ-luca.martinet
## File description:
## Makefile
##

CC 	= 	gcc

SRC 	=		src/main.c								\
				src/menubar.c							\
				src/menubar_pt2.c						\
				src/select_button.c						\
				src/coloration.c						\
				src/extra.c								\

OBJ     = 		$(SRC:.c=.o)

NAME	=		 my_paint

CFLAGS 	=	-W -Wall -Wextra -pedantic

CSFML	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:	$(OBJ)
				gcc $(OBJ) -o $(NAME) -I../includes $(CFLAGS) $(CSFML)
				@echo -e "\033[1;32mCompiling Finished\033[0m"

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		@echo -e "\033[1;31mfclean done\033[0m"

re: fclean all

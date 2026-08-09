##
## EPITECH PROJECT, 2024
## B-PDG-300-BAR-3-1-PDGD04am-luca.martinet
## File description:
## Makefile
##

SRC =	z.c

INC_PATH =	include

NAME =	z

OBJ = 	$(SRC:.c=.o)

CFLAGS = -I. -I$(INC_PATH) -Wall -Wextra

$(NAME):	$(OBJ)	$(OBJMAIN)
		@gcc -o $(NAME) $(OBJ) $(CFLAGS)

all:	$(NAME)

debug:	CFLAGS += -g
debug:	fclean all
		@gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -fr $(NAME)

re:	fclean all

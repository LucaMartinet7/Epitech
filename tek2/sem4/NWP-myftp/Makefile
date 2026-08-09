##
## EPITECH PROJECT, 2024
## B-NWP-400-BAR-4-1-myftp-luca.martinet
## File description:
## Makefile
##

SRC =	$(wildcard src/*.c) \
		$(wildcard src/server/*.c) \
		$(wildcard src/commands/*.c)

INC_PATH =	include

NAME =	myftp

OBJ = 	$(SRC:.c=.o)

CFLAGS = -I$(INC_PATH) -Wall -Wextra -Werror -g3

all:	$(NAME)

$(NAME):	$(OBJ)	$(OBJMAIN)
		@gcc -o $(NAME) $(OBJ) $(CFLAGS)
		@echo -e '\033[0;32m✔ Compilation Complete\033[0m'

clean:
		rm -f $(OBJ)
		@echo -e '\033[0;32m✔ clean\033[0m'
fclean:	clean
		rm -fr $(NAME)
		@echo -e '\033[0;32m✔ fclean\033[0m'

re:	fclean all

.PHONY:	all clean fclean re

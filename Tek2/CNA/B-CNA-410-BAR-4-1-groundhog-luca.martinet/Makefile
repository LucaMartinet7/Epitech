##
## EPITECH PROJECT, 2024
## B-CNA-410-BAR-4-1-groundhog-luca.martinet [WSL: Ubuntu]
## File description:
## Makefile
##

SRC_DIR		=	./src/

NAME		=	groundhog

$(NAME)	:
			cp $(SRC_DIR)groundhog.py ./
			mv groundhog.py groundhog
			chmod +x groundhog

all	:		$(NAME)

clean:
			rm -rf groundhog

fclean:		clean

re:			fclean all

.PHONY: all clean fclean re

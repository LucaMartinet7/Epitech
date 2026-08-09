##
## EPITECH PROJECT, 2024
## B-YEP-400-BAR-4-1-zappy-noe.kurata
## File description:
## Makefile
##

NAME    =   zappy_gui

all:    scons $(NAME)

scons:
	scons platform=linux

$(NAME):
	echo '#!/bin/sh'    > $(NAME)
	echo 'cd demo && godot-4 -d main.tscn' >> $(NAME)
	chmod +x $(NAME)

clean:
	find . -name '*.os' -delete

fclean: clean
	rm -f $(NAME)

re:	clean all

.PHONY:	all scons clean re

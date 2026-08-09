##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## Makefile
##

SRC_SERVER 	= 	server

SRC_AI	= ai

SRC_GUI	= sfml

all:	server ai

server:
	@ make -C $(SRC_SERVER) -s
	@ make -C $(SRC_AI) -s
	@ make -C $(SRC_GUI) -s

clean:
	@ make clean -C $(SRC_SERVER) -s
	@ make clean -C $(SRC_AI) -s
	@ make clean -C $(SRC_GUI) -s

fclean:
	@ make fclean -C $(SRC_SERVER) -s
	@ make fclean -C $(SRC_AI) -s
	@ make fclean -C $(SRC_GUI) -s

re:
	@ make re -C $(SRC_SERVER) -s
	@ make re -C $(SRC_AI) -s
	@ make re -C $(SRC_GUI) -s

.PHONY: all server ai clean fclean re

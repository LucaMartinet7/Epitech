##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## Makefile
##

SRC 	+= 	src/handle_error.c	\
			src/get_commands.c	\
			src/manage_file.c	\
			src/connection.c	\
			src/set_player.c	\
			src/set_value.c	\
			src/movement.c	\
			src/set_pos.c	\
			src/server.c	\
			src/object.c	\
			src/look.c	\
			src/map.c	\
			src/main.c	\

NAME 	= 	../zappy_server

OBJ 	= 	$(SRC:.c=.o)

CFLAGS 	+= 	-I./include/ -g3 -W

RED		=	\033[0;31m
GREEN	=	\033[0;32m
PINK	=	\033[1;95m
CYAN	=	\033[1;36m
YELLOW	=	\033[0;33m
NC		=	\033[0m

all:	$(NAME)

$(NAME):	$(OBJ)
	@echo "$(GREEN)Building server executable $(NAME)$(NC)"
	@gcc -o $@ $^ $(LDFLAGS)

%.o: %.c
	@ $(CC) -c $< -o $@ $(CFLAGS) && \
	(printf "$(NAME) [$(GREEN)✔$(NC)] %b\n" $<) || \
	(printf "[$(RED)✘$(NC)] $(RED)%b\n" $< ; exit 1)

clean:
	@echo "$(YELLOW)Cleaning server object files $(NC)"
	@rm -f $(OBJ)

fclean:	clean
	@echo "$(YELLOW)Cleaning server executable $(NC)"
	@rm -f $(NAME)

re:	fclean all

auteur:
	echo $(USER) > auteur

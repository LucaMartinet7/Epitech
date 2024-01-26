##
## EPITECH PROJECT, 2022
## B-CPE-110-PAR-1-2-BSQ-luca.martinet
## File description:
## Makefile
##

CC 	= 	gcc

SRC 	=		main.c						\
				counters.c					\
				open_file.c					\
				error_handling.c			\
				char_to_char2.c				\
				print_arrays.c				\
				array_to_numbers.c			\
				solve_maze.c				\
				print_map_solve.c			\
				is_solved.c

OBJ     = 		$(SRC:.c=.o)

NAME	=		 solver

CFLAGS 	=	-W -Wall -Wextra

all:	$(NAME)

$(NAME): $(OBJ)
		gcc -o $(NAME) $(OBJ)
		@echo -e "\033[1;32msolver make done\033[0m"
clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		@echo -e "\033[1;31mfclean solver done\033[0m"

re: fclean all

##
## EPITECH PROJECT, 2022
## B-CPE-110-PAR-1-2-BSQ-luca.martinet
## File description:
## Makefile
##

CC 	= 	gcc

SRC 	=		src/main.c								\
				src/minishell.c							\
				src/builtins.c							\
				src/check.c								\
				src/path.c								\
				src/array.c								\
				src/builtin_cd.c						\
				src/builtin_env.c						\
				lib/my/my_strcmp.c						\
				lib/my/my_printf/my_printf.c			\
				lib/my/my_put_nbr.c						\
				lib/my/my_putchar.c						\
				lib/my/my_putstr.c						\
				lib/my/my_revstr.c						\
				lib/my/my_strlen.c						\
				lib/my/my_printf/flags/int_to_oct.c		\
				lib/my/my_printf/flags/int_to_bin.c		\
				lib/my/my_printf/flags/my_put_u.c		\
				lib/my/my_getnbr.c						\
				lib/my/my_printf/flags/my_put_x_lower.c \
				lib/my/my_printf/flags/my_put_x_upper.c	\
				lib/my/my_strncmp.c						\
				lib/my/my_strcat.c						\
				lib/my/my_strcpy.c						\
				lib/my/my_str_array_dup.c				\
				lib/my/my_str_to_word_array.c			\
				lib/my/my_str_to_word_array_pt2.c		\
				lib/my/print_array.c

OBJ     = 		$(SRC:.c=.o)

NAME	=		 mysh

DEBUG = -pedantic -g3

CFLAGS 	=	-W -Wall -Wextra

all:	$(NAME)

$(NAME): $(OBJ)
		gcc -o $(NAME) $(OBJ)
		@echo -e "\033[1;32mFinish Compiling\033[0m"

debug:
		gcc -o $(NAME) $(SRC) $(CFLAGS) $(DEBUG)
		@echo -e "\033[1;32mFinish Compiling DEBUG\033[0m"

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		@echo -e "\033[1;31mfclean done\033[0m"

re: fclean all

.PHONY: all clean fclean re

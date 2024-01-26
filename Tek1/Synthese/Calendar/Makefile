##
## EPITECH PROJECT, 2023
## B-SYN-200-PAR-2-1-calendar-luca.martinet
## File description:
## Makefile
##

CC ?= gcc

SRC := $(wildcard src/*.c)

OBJ := $(SRC:.c=.o)

NAME := calendar

DEBUG := -pedantic -g3

CFLAGS := -W -Wall -Wextra -g3

CPPFLAGS :=	-iquote include

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
	@echo -e "\033[1;32mFinish Compiling\033[0m"

clean:
	rm -rf $(OBJ)
	rm -rf vgcore.*

debug:
		$(CC) -o $(NAME) $(SRC) $(CFLAGS) $(DEBUG)
		@echo -e "\033[1;32mFinish Compiling DEBUG\033[0m"

fclean: clean
	rm -rf $(NAME)
	rm -rf vgcore.*
	rm -rf *.gcda
	rm -rf *.gcno
	@echo -e "\033[1;31mfclean done\033[0m"

re: fclean all

.PHONY: all clean debug fclean re

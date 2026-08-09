##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

CC		=	gcc
MAIN		=	src/main.c
SRC		=	src/mini_printf.c
UT_SRC		=	tests/test.c

NAME		=	mini_printf
UT_NAME		=	unit_tests

LIBRARY		=	-l include

OBJ		=	$(SRC:.c=.O)

all: tests

$(NAME): $(MAIN:.c=.o) $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

tests_run:
	$(CC) -o $(UT_NAME) -l include/ --coverage $(SRC) $(UT_SRC) -lcriterion
	$(UT_NAME)

clean: SRC = $(MAIN)

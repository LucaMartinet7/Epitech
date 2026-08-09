##
## EPITECH PROJECT, 2024
## B-OOP-400-BAR-4-1-tekspice-noe.kurata
## File description:
## Makefile
##

CC	=	g++

HEADERS_DIR	=	include

SRC	=	$(wildcard src/*.cpp)

OBJ = $(SRC:.cpp=.o)

CPPFLAGS = -Wall -Wextra -iquote $(HEADERS_DIR)

VERSION = -std=c++17

NAME = nanotekspice

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(VERSION) -o $@ $^

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

bin:	all
	rm -rf $(OBJ)
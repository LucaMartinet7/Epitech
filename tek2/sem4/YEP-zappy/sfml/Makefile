##
## EPITECH PROJECT, 2024
## B-YEP-400-BAR-4-1-zappy-noe.kurata [WSL: Ubuntu]
## File description:
## Makefile
##

CXX = g++

CXXFLAGS = -Wall -Wextra -Iinclude -std=c++17

LDFLAGS = 	-lsfml-graphics -lsfml-window -lsfml-system \
 			-lsfml-network -lsfml-audio

SRC = $(wildcard src/*.cpp)

OBJ = $(SRC:.cpp=.o)

NAME = ../zappy_gui

RED		=	\033[0;31m
GREEN	=	\033[0;32m
PINK	=	\033[1;95m
CYAN	=	\033[1;36m
YELLOW	=	\033[0;33m
NC		=	\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)Building gui executable $(NAME)$(NC)"
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS) && \
	(printf "$(NAME) [$(GREEN)✔$(NC)] %b\n" $<) || \
	(printf "[$(RED)✘$(NC)] $(RED)%b\n" $< ; exit 1)

clean:
	@echo "$(PINK)Cleaning gui object files $(NC)"
	rm -f $(OBJ)

fclean: clean
	@echo "$(PINK)Cleaning gui executable $(NC)"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

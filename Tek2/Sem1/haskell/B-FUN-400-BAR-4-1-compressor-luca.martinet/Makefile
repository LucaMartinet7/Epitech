##
## EPITECH PROJECT, 2024
## B-FUN-400-BAR-4-1-compressor-luca.martinet
## File description:
## Makefile
##

NAME = imageCompressor

BINARY = $(shell stack path --local-install-root)

all: $(NAME)

$(NAME):
	stack build
	cp $(BINARY)/bin/$(NAME)-exe ./$(NAME)

clean:
	stack clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
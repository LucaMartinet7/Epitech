##
## EPITECH PROJECT, 2024
## B-PDG-300-BAR-3-1-PDGRUSH1-luca.martinet
## File description:
## Makefile
##

NAME =  pushswap_checker

GHC = ghc

SRC = main.hs \

OBJ =   $(SRC:.hs=.o)

OBJ +=   $(SRC:.hs=.hi)

all:    $(NAME)

$(NAME):
	$(GHC) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)
	rm -f *~ *#

fclean: clean
	rm -f $(NAME)

re: fclean all
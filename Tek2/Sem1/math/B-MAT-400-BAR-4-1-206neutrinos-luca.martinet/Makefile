##
## EPITECH PROJECT, 2024
## B-MAT-400-BAR-4-1-206neutrinos-luca.martinet [WSL: Ubuntu]
## File description:
## Makefile
##

CC			=	g++
RM			=	rm -f

SRCPATH		=	src/
TESTPATH	=	tests

MAIN 		= 	$(SRCPATH)main.cpp

CFLAGS		+=	-Wextra -Wall -Wpedantic
CPPFLAGS	+=	-iquote include/
TESTFLAGS	=	--coverage -lcriterion

SRC			=	$(SRCPATH)206neutrinos.cpp	\
				$(SRCPATH)loop.cpp

SRCTEST		=	$(TESTPATH)/tests206neutrinos.cpp

BINARY		=	206neutrinos

FLAGS		=	$(CFLAGS) $(CPPFLAGS)

OBJ 		= 	$(SRC:.cpp=.o) \
				$(MAIN:.cpp=.o)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

all: $(OBJ)
	$(CC) $(FLAGS) -o $(BINARY) $(OBJ)

tests_run:
	$(CC) $(FLAGS) -o unit_tests $(SRC) $(SRCTEST) $(TESTFLAGS)
	./unit_tests
	gcovr --exclude tests/ --branches

clean:
	$(RM) $(OBJ)
	$(RM) *~

fclean:			clean
	$(RM) $(BINARY)
	$(RM) unit_tests
	$(RM) *.gcno
	$(RM) *.gcda
	$(RM) *.gcov

re:				fclean all

.PHONY: all fclean clean re core games graphicals

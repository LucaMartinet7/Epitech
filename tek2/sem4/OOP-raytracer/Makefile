##
## EPITECH PROJECT, 2024
## B-OOP-400-BAR-4-1-raytracer-jules.dufraiche
## File description:
## Makefile
##

SRCPATH		 =	./src/
TESTPATH	 =	./tests/
CC		     =	g++
RM			 =	rm -f

CFLAGS		+=	-Wextra -Wall -Wpedantic
CPPFLAGS	+=	-iquote include
LDFLAGS 	+= 	-lconfig++
TESTFLAGS	 =  -I./include --coverage -lcriterion

SRC			 =	$(wildcard $(SRCPATH)*.cpp)

TESTS		 =	$(wildcard $(TESTPATH)*.cpp) \
					$(filter-out $(SRCPATH)main.cpp,$(SRC))

OBJ			 =	$(SRC:.cpp=.o)

BINARY		 =	raytracer
TEST_BIN	 =	unit_tests

all:			$(BINARY)

$(BINARY):		$(OBJ)
		$(CC) -o $(BINARY) $(OBJ) $(LDFLAGS)

clean:
		$(RM) $(OBJ)
		find \( -name "*.gcda" -or -name "*.gcno" \) -delete

fclean:			 clean
		$(RM) $(BINARY)
		$(RM) $(TEST_BIN)

re:				 fclean all

unit_tests:
		$(CC) -o $(TEST_BIN) $(TESTS) $(TESTFLAGS)


tests_run:		unit_tests
		./$(TEST_BIN)

.PHONY: tests_run unit_tests all clean fclean re

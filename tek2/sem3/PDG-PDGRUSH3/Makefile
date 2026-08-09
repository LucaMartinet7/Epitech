##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRCPATH 	=	./src/
DISPLAYPATH =	./src/Displays/
MODULEPATH 	=	./src/Modules/
TESTPATH 	=	./tests/
CC			=	g++
RM			=	rm -f

CFLAGS		+= 	-Wextra -Wall -Wpedantic
LFLAGS 		 =  -lncurses -lsfml-graphics -lsfml-window -lsfml-system
CPPFLAGS	+=	-iquote include

SRC     	=	$(wildcard $(SRCPATH)*.cpp) 			\
				$(wildcard $(DISPLAYPATH)*.cpp) 	    \
				$(wildcard $(MODULEPATH)*.cpp)

OBJ 		= 	$(SRC:.cpp=.o)

NAME 		=    MyGKrellm

all: 			$(NAME)

$(NAME):		$(OBJ)
				$(CC) -o $(NAME) $(OBJ) $(LFLAGS)

clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME)

re: 			fclean all

.PHONY: all clean fclean re

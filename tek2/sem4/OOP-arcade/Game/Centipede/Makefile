##
## EPITECH PROJECT, 2024
## B-OOP-400-BAR-4-1-arcade-luca.martinet
## File description:
## Makefile
##

SRCPATH		=	./src/
OBJPATH		=	../../Objects/src/
EVTPATH		=	../../Event/src/
LIBPATH		=	../../lib/
CC			=	g++
RM			=	rm -f
MV			=	mv

CFLAGS		+=	-Wextra -Wall -Wpedantic
CPPFLAGS	+=	-iquote include -iquote ../../Objects/include \
				-iquote ../../Event/include -iquote ../../include
FLAGS		=	-fPIC -shared $(CFLAGS) $(CPPFLAGS)

SRC			=	$(SRCPATH)entryPoint.cpp	\
				$(SRCPATH)gameManager.cpp	\
				$(SRCPATH)mapManager.cpp	\
				$(SRCPATH)eventsManager.cpp	\
				$(SRCPATH)centipedeManager.cpp	\
				$(OBJPATH)AObject.cpp		\
				$(EVTPATH)AEvent.cpp

BINARY		=	arcade_centipede.so

all:
				$(CC) -o $(BINARY) $(SRC) $(FLAGS)
				$(MV) $(BINARY) $(LIBPATH)

fclean:
				$(RM) $(LIBPATH)$(BINARY)

re:				fclean all

.PHONY: all fclean re

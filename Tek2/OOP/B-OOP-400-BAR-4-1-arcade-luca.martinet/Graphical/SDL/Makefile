##
## EPITECH PROJECT, 2024
## B-OOP-400-BAR-4-1-arcade-luca.martinet [WSL: Ubuntu]
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
FLAGS		=	-fPIC -shared -lSDL2main -lSDL2 -lSDL2_ttf \
				-lSDL2_image $(CFLAGS) $(CPPFLAGS)

SRC			=	$(SRCPATH)entryPoint.cpp	\
				$(SRCPATH)eventManager.cpp 	\
				$(SRCPATH)screenManager.cpp	\
				$(SRCPATH)textureManager.cpp\
				$(EVTPATH)AEvent.cpp

BINARY		=	arcade_sdl2.so

all:
				$(CC) -o $(BINARY) $(SRC) $(FLAGS)
				$(MV) $(BINARY) $(LIBPATH)

fclean:
				$(RM) $(LIBPATH)$(BINARY)

re:				fclean all

.PHONY: all fclean re

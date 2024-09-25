##
## EPITECH PROJECT, 2024
## B-OOP-400-BAR-4-1-arcade-luca.martinet
## File description:
## Makefile
##

SRCPATH		=	./Core/src/
OBJPATH		=	./Objects/src/
EVTPATH		=	./Event/src/
LIBPATH		=	../../lib/
GAMESDIRS	=	Game/Snake Game/Centipede
GRAPHDIRS	=	Graphical/SFML Graphical/SDL Graphical/NCurses
CC			=	g++
RM			=	rm -f


CFLAGS		+=	-Wextra -Wall -Wpedantic
CPPFLAGS	+=	-iquote ./Core/include -iquote ./Objects/include \
				-iquote ./Event/include -iquote ./include
FLAGS		=	$(CFLAGS) $(CPPFLAGS)

SRC			=	$(SRCPATH)main.cpp	\
				$(SRCPATH)core.cpp	\
				$(SRCPATH)lib.cpp	\
				$(SRCPATH)utils.cpp	\
				$(SRCPATH)menu.cpp	\
				$(OBJPATH)AObject.cpp\
				$(EVTPATH)AEvent.cpp

BINARY		=	arcade

all:			core games graphicals

clean:
				find \( -name "*.so" \) -delete

fclean:			clean
				$(RM) $(BINARY)

core:
				$(CC) -o $(BINARY) $(SRC) $(FLAGS)

games:
				$(foreach dir, $(GAMESDIRS), $(MAKE) -C $(dir);)

graphicals:
				$(foreach dir, $(GRAPHDIRS), $(MAKE) -C $(dir);)

re:				fclean all

.PHONY: all fclean clean re core games graphicals

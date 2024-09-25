##
## EPITECH PROJECT, 2024
## B-PSU-400-BAR-4-1-strace-jules.dufraiche
## File description:
## Makefile
##

CLIENTPATH	=	./src/client/
SERVERPATH	=	./src/server/
SHAREDPATH	=	./src/shared/
TESTPATH	=	./tests/
CC			=	gcc
RM			=	rm -f

CFLAGS		+=	-Wextra -Wall -Wpedantic
CPPFLAGS	+=	-iquote include
TESTFLAGS	=	-I./include --coverage -lcriterion

CLIENTSRC	=	$(wildcard $(CLIENTPATH)*.c) \
				$(wildcard $(SHAREDPATH)*.c)

SERVERSRC	=	$(wildcard $(SERVERPATH)*.c) \
				$(wildcard $(SHAREDPATH)*.c)

CLIENTOBJ	=	$(CLIENTSRC:.c=.o)
SERVEROBJ	=	$(SERVERSRC:.c=.o)

CLIENTBIN	=	myteams_cli
SERVERBIN	=	myteams_server

LIBINCLUDE	=	-L ./libs/myteams/ -lmyteams

all:			client server

client:			$(CLIENTOBJ)
				$(CC) -o $(CLIENTBIN) $(CLIENTOBJ) $(LIBINCLUDE)

server:			$(SERVEROBJ)
				$(CC) -o $(SERVERBIN) $(SERVEROBJ) $(LIBINCLUDE)

clean:
				$(RM) $(CLIENTOBJ) $(SERVEROBJ)

fclean:			clean
				$(RM) $(SERVERBIN) $(CLIENTBIN)

re:				fclean all

.PHONY: client server all clean fclean re

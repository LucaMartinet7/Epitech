##
## EPITECH PROJECT, 2024
## B-ASM-400-BAR-4-1-asmminilibc-luca.martinet
## File description:
## Makefile
##

SRCPATH 	=	src/
RM			=	rm -f

CFLAGS		+= 	-Wextra -Wall -Wpedantic
CPPFLAGS	+=	-iquote include

SRC     	=	$(wildcard $(SRCPATH)*.asm)

OBJ 		= 	$(SRC:.asm=.o)

NAME 		=    libasm.so

all: 			$(NAME)

$(NAME):		$(OBJ)
				ld -o $(NAME) $(OBJ) -shared

clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME)

re: 			fclean all

%.o: %.asm
				nasm -f elf64 -o $@ $<

.PHONY: all clean fclean re %.o
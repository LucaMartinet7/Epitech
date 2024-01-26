##
## EPITECH PROJECT, 2022
## make file
## File description:
## make file
##

SRC	=	lib/my/my_printf/my_printf.c			\
		lib/my/my_put_nbr.c						\
		lib/my/my_putchar.c						\
		lib/my/my_putstr.c						\
		lib/my/my_revstr.c						\
		lib/my/my_strlen.c						\
		lib/my/my_printf/flags/int_to_oct.c		\
		lib/my/my_printf/flags/int_to_bin.c		\
		lib/my/my_printf/flags/my_put_u.c		\
		lib/my/my_getnbr.c						\
		lib/my/my_printf/flags/my_put_x_lower.c \
		lib/my/my_printf/flags/my_put_x_upper.c	\
		src/case_l.c							\
		src/block.c

OBJ	=	$(SRC:.c=.o)

NAME_LIB	=	libmy.a

all:	$(NAME_LIB)

copy:
	cp $(NAME_LIB) lib/my/
clean:
	rm -f lib/my/*.o
	rm -f lib/my/my_printf/flags/*.o
	rm -f $(NAME_LIB)
	rm -f lib/my/$(NAME_LIB)
	rm -f *.o
	rm -f lib/my/my_printf/*.o
	rm -f src/*.o

fclean:	clean
		rm -f $(NAME)

re:
	gcc -o my_ls src/my_ls.c -L ./lib/my/ -I ./include/ -lmy

$(NAME_LIB):	$(OBJ)
	ar -rc $(NAME_LIB) $(OBJ)
	make copy
	make re

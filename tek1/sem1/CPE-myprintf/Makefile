##
## EPITECH PROJECT, 2022
## make file
## File description:
## make file
##

SRC	=	my_printf.c			\
		lib/my/my_put_nbr.c	\
		lib/my/my_putchar.c	\
		lib/my/my_putstr.c	\
		lib/my/my_revstr.c	\
		lib/my/my_strlen.c	\
		flags/int_to_oct.c	\
		flags/int_to_bin.c	\
		flags/my_put_u.c	\
		lib/my/my_getnbr.c	\
		flags/my_put_x_lower.c \
		flags/my_put_x_upper.c \

OBJ	=	$(SRC:.c=.o)

NAME_LIB	=	libmy.a

all:	$(NAME_LIB)

copy:
	cp $(NAME_LIB) lib/my/
clean:
	rm -f lib/my/*.o
	rm -f flags/*.o
	rm -f $(NAME_LIB)
	rm -f lib/my/$(NAME_LIB)
	rm -f *.o

fclean:	clean
		rm -f $(NAME)

re:	fclean all

$(NAME_LIB):	$(OBJ)
	ar -rc $(NAME_LIB) $(OBJ)
	make copy

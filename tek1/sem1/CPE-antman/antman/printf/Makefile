##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SRC		=	my_printf.c					\
			lib/show_number.c			\
			lib/my_putchar.c			\
			lib/show_string.c			\
			lib/reverse_string.c		\
			lib/my_strlength.c			\
			lib/my_strcpy.c				\
			lib/my_strncpy.c			\
			lib/my_strncmp.c			\
			lib/my_strstr.c				\
			lib/openfile.c				\
			lib/str2linearray.c			\
			lib/to_number.c 			\
			lib/is_prime_number.c		\
			lib/my_compute_power_rec.c	\
			lib/my_str2wordarray.c		\
			lib/my_strcat.c				\
			flags/my_put_oct.c			\
			flags/my_put_bin.c			\
			flags/my_put_uns.c			\
			flags/my_put_hex.c			\
			flags/backn.c				\

OBJ	=	$(SRC:.c=.o)

NAME_LIB	=	libmy.a

all:	$(OBJ)
	ar -rc $(NAME_LIB) $(OBJ)
	make copy

copy:
		cp $(NAME_LIB) lib/

clean:
	rm -f lib/*.o
	rm -f flags/*.o
	rm -f $(NAME_LIB)
	rm -f lib/$(NAME_LIB)
	rm -f *.o

fclean:	clean
		rm -f $(NAME)

re:	fclean all

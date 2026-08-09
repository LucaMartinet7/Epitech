##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile
##

NAME	=	libmy.a

SRC	=	my_put_unsigned_nbr.c	\
		my_decimal_to_octal.c	\
		my_put_binary.c			\
		my_strcmp.c 			\
		my_strcpy.c				\
		my_strncpy.c			\
		my_strcat.c				\
		my_revstr.c				\
		my_strncat.c			\
		my_putchar.c			\
		my_isneg.c				\
		my_put_nbr.c			\
		my_putstr.c				\
		my_strlen.c				\
		my_getnbr.c				\
		my_strdup.c				\

OBJ	=	$(SRC:.c=.o)

UT_NAME	=	unit_test

CFLAGS	+=	-Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../../$(NAME)
	@echo -e "\033[1;32mCompilation Complete\033[0m"

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) ../../$(NAME)
	@echo -e "\033[1;32mfclean Complete\033[0m"

re:	fclean all

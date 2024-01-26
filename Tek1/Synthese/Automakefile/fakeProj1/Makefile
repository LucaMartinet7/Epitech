##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

SRC := $(wildcard src/*.c)

OBJ := $(SRC:.c=.o)

NAME := fakeProj

CC := clang

CFLAGS := -ftest-coverage -O2

LDFLAGS := -I ./include

BCK_DIR := backup

ZIP := tar

ZIPFLAGS := -cvvf

UNZIP := tar

UNZIPFLAGS := -xvf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

archive:
	$(ZIP) $(ZIPFLAGS) $(BCK_DIR)/backup.$(ZIP) $(SRC)
	@$ ./version.sh +

revert:
	$(UNZIP) $(UNZIPFLAGS) $(BCK_DIR)/backup.$(ZIP)
	@$ ./version.sh -

num:
	@$ cat version

delete:
	rm -f $(BCK_DIR)/backup.$(ZIP)

.PHONY: all clean fclean re archive revert num delete

##
## EPITECH PROJECT, 2024
## B-FUN-400-BAR-4-1-mypandoc-jules.dufraiche
## File description:
## Makefile
##

BINARY		=	mypandoc
STACK		=	stack

BUILD_DIR 	= $(shell $(STACK) path --local-install-root)

all: $(BINARY)

$(BINARY):
		$(STACK) build
		cp $(BUILD_DIR)/bin/$(BINARY)-exe ./$(BINARY)

clean:
		$(STACK) clean

fclean: clean
		$(RM) $(BINARY)

re:		fclean all

.PHONY: all clean fclean tests_run re

##
## EPITECH PROJECT, 2024
## B-YEP-400-BAR-4-1-zappy-noe.kurata
## File description:
## Makefile
##

SRC_DIR	=	src/
SCRIPT  =   client.py

NAME	=	../zappy_ai

RED     =   \033[0;31m
GREEN   =   \033[0;32m
PINK    =   \033[1;95m
CYAN    =   \033[1;36m
YELLOW  =   \033[0;33m
NC      =   \033[0m;

all: $(NAME)

$(NAME):
	@echo "$(CYAN)Copying $(SRC_DIR)$(SCRIPT) to $(NAME)$(NC)"
	@cp $(SRC_DIR)$(SCRIPT) $(NAME)
	@chmod +x $(NAME)
	@echo "$(GREEN)$(NAME) created successfully.$(NC)"

clean:
	@echo "$(YELLOW)Cleaning up...$(NC)"
	@rm -f $(NAME)
	@echo "$(GREEN)Cleaned up $(NAME).$(NC)"

fclean: clean

re: clean all

run:
	cd $(SRC_DIR) && python3 $(SCRIPT) $(port) $(name) $(ip)

.PHONY: all clean fclean re run

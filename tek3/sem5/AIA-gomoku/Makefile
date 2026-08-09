NAME = pbrain-gomoku-ai
SRC = main.py

$(NAME): $(SRC)
	@echo "\033[1;34m➔  Copying $(SRC) to $(NAME)\033[0m"
	@cp $(SRC) $(NAME) > /dev/null 2>&1
	@echo "\033[1;32m✔  Making $(NAME) executable\033[0m"
	@chmod +x $(NAME) > /dev/null 2>&1

all: $(NAME)

exe:
	pyinstaller --onefile $(SRC)
	@mv ./dist/main $(NAME).exe

clean:
	@echo "\033[1;33m🗑️  Cleaning up...\033[0m"
	@rm -f $(NAME)
	@rm -rf src/__pycache__
	@rm -fr dist/
	@rm -fr *.spec
	@rm -rf $(NAME).exe

fclean: clean
	@echo "\033[1;33m🗑️  Full cleanup completed.\033[0m"

re: fclean all
	@echo "\033[1;33m🔄 Rebuilding the project...\033[0m"

.PHONY: all clean fclean re

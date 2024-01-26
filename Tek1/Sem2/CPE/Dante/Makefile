##
## EPITECH PROJECT, 2022
## B-CPE-200-PAR-2-2-dante-noe.kurata
## File description:
## Makefile
##

all:
	make -C solver/
	make -C generator/
	@echo -e "\033[1;32mboth make done\033[0m"

clean:
		make clean -C solver/
		make clean -C generator/

fclean: clean
		make fclean -C solver/
		make fclean -C generator/
		@echo -e "\033[1;31mboth fclean done\033[0m"


re:     fclean all

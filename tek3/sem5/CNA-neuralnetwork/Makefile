CFLAGS = -Wall -Wextra -Werror
PYTHON = python3
SRC_DIR = src
GENERATE_DIR = generator
ANALYZE_DIR = analyzer
OBJ_DIR = obj

GENERATOR_SRC = $(SRC_DIR)/$(GENERATE_DIR)/my_torch_generator.py
GENERATOR_BIN = my_torch_generator

ANALYZER_SRC = $(SRC_DIR)/$(ANALYZE_DIR)/my_torch_analyzer.py
ANALYZER_BIN = my_torch_analyzer


all: $(GENERATOR_BIN) $(ANALYZER_BIN)

$(GENERATOR_BIN): $(GENERATOR_SRC)
	cp $< $@
	chmod +x $@

$(ANALYZER_BIN): $(ANALYZER_SRC)
	cp $< $@
	chmod +x $@

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(GENERATOR_BIN) $(ANALYZER_BIN)

fclean: clean

re: fclean all
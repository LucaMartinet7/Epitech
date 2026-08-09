from .utils import debug_print
from .minmax import Minimax
from .board import Board
from sys import exit

import random

class Command:
    def __init__(self, game):
        """
        Initialize the Command class with a reference to the game instance.

        Args:
            game (Game): The game instance.
        """
        self.parser = game.parserClass
        self.commands = {
            "BOARD": self.handle_board,
            "START": self.handle_start,
            "TURN": self.handle_turn,
            "BEGIN": self.handle_begin,
            "INFO": self.handle_info,
            "END": self.handle_end,
            "ABOUT": self.handle_about
        }
        self.info = {
            "timeout_turn": 0,
            "timeout_match": 0,
            "max_memory": 0,
            "time_left": 2147483647,
            "game_type": 0,
            "rule": 0,
            "evaluate": (0, 0),
            "folder": ""
        }
        self.minimax = Minimax(20)

    def handle_start(self) -> bool:
        """
        Handle the START command to initialize the board with the given size.

        Returns:
            bool: True if the board is initialized successfully, False otherwise.
        """
        try:
            parsed_input = self.parser.get_parsed_input()
            if len(parsed_input) != 2:
                raise ValueError("Invalid input length")
            board_size = int(parsed_input[1])
            if board_size < 5:
                raise ValueError("Board size must be at least 5")

            self.minimax.boardsize = board_size
            self.minimax.board = Board(board_size)
            # print(self.minimax.board)

        except ValueError as e:
            print(f"ERROR: {e}", flush=True)
            return False
        print("OK", flush=True)
        return True

    def handle_about(self) -> None:
        """
        Handle the ABOUT command to print information about the bot.
        """
        name = 'name="dans le poto"'
        version = 'version="1.0"'
        authors = 'author="Luca Martinet, Noe Kurata"'
        country = 'country="GER"'
        print(f"{name}, {version}, {authors}, {country}", flush=True)

    def handle_turn(self) -> None:
        """
        Handle the TURN command to process the opponent's move and make the bot's move.
        """
        try:
            parsed_input = self.parser.get_parsed_input()
            if len(parsed_input) != 2:
                raise ValueError
            x, y = map(int, parsed_input[1].split(","))
            if not (0 <= x < self.minimax.board.board_size and 0 <= y < self.minimax.board.board_size):
                raise ValueError
            if self.minimax.board.get_pawn(x, y) != 0:
                raise ValueError
            else:
                self.minimax.board.set_pawn(x, y, 2)  # Player's move
            self.minimax.minimax()
        except ValueError:
            print("ERROR: Invalid input format or move", flush=True)

    def handle_begin(self) -> None:
        """
        Handle the BEGIN command to make the first move.
        """
        empty_cells = [(i, j) for i in range(self.minimax.board.board_size) for j in range(self.minimax.board.board_size) if self.minimax.board.board[i][j] == 0]
        if empty_cells:
            move = random.choice(empty_cells)
            print(f"{move[0]},{move[1]}", flush=True)
        else:
            print("ERROR: No empty cells available", flush=True)

    def handle_board(self) -> None:
        """
        Handle the BOARD command to set up the board state from the input.
        """
        while True:
            self.parser.read_player_input()
            line = self.parser.get_parsed_input()
            if line[0] == "DONE":
                break
            try:
                positions = line[0].split(",")
                if len(positions) != 3:
                    raise ValueError
                x, y, player = int(positions[0]), int(positions[1]), int(positions[2])
                if not (0 <= x < self.minimax.board.board_size and 0 <= y < self.minimax.board.board_size and player in [1, 2]):
                    raise ValueError
                self.minimax.board.set_pawn(y, x, player)
            except ValueError:
                print("DEBUG Message - Failure on Board Input", flush=True)
                return
        self.minimax.minimax()

    def handle_info(self) -> None:
        """
        Handle the INFO command to update the bot's configuration.

        The INFO command provides various configuration parameters such as timeout, memory, game type, etc.
        """
        parsed_input = self.parser.get_parsed_input()
        if len(parsed_input) != 3:
            return
        key, value = parsed_input[1], parsed_input[2]
        if key in self.info:
            if key == "evaluate":
                self.info[key] = tuple(map(int, value.split(",")))
            elif key in ["timeout_turn", "timeout_match", "max_memory", "time_left", "game_type", "rule"]:
                self.info[key] = int(value)
            elif key == "folder":
                self.info[key] = value
        else:
            debug_print(f"Unknown INFO key: {key}")

    def handle_end(self) -> None:
        """
        Handle the END command to terminate the game.
        """
        exit(0)
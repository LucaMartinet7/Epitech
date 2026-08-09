from .parser import Parser
from .commands import Command

class Game:
    def __init__(self):
        """
        Initialize the Game class with a Parser and Command instance.
        """
        self.parserClass = Parser()
        self.commandClass = Command(self)

    def run(self) -> int:
        """
        Run the game loop, reading player input and executing commands.

        Returns:
            int: The exit status of the game.
        """
        while True:
            self.parserClass.read_player_input()
            parsed_input = self.parserClass.get_parsed_input()
            # debug_print(f"parsed_input in run loop = {parsed_input}")
            if not parsed_input:
                continue
            command = parsed_input[0]
            try:
                self.commandClass.commands[command]()
            except KeyError:
                print(f"UNKNOWN message - command {command} not existing.", flush=True)
class Parser:
    def __init__(self):
        """Initialize the Parser class with default values."""
        self.player_input_str = str()
        self.parsed_input = list()

    def get_parsed_input(self) -> list[str]:
        """
        Get the parsed input as a list of strings.

        Returns:
            list[str]: The parsed input.
        """
        return self.parsed_input

    def read_player_input(self) -> None:
        """
        Read input from the player, handle exceptions, and parse the input into a list of strings.
        """
        try:
            self.player_input_str = input()
        except EOFError:
            exit(0)
        except KeyboardInterrupt:
            exit(0)

        self.parsed_input = self.player_input_str.rstrip().split(" ")

    def get_input(self) -> str:
        """
        Get the raw input string from the player.

        Returns:
            str: The raw input string.
        """
        return self.player_input_str
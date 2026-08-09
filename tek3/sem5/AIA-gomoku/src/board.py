class Board:
    def __init__(self, size):
        """
        Initialize the Board class with a given size.

        Args:
            size (int): The size of the board.
        """
        self.board_size = size
        self.board = self.reset_board(size)

    @staticmethod
    def reset_board(board_size):
        """
        Reset the board to its initial state.

        Args:
            board_size (int): The size of the board.

        Returns:
            list[list[int]]: A 2D list representing the board with all cells set to 0.
        """
        return [[0] * board_size for _ in range(board_size)]

    def set_pawn(self, x: int, y: int, player: int) -> None:
        """
        Set a pawn on the board at the specified coordinates.

        Args:
            x (int): The x-coordinate.
            y (int): The y-coordinate.
            player (int): The player ID (1 or 2).
        """
        self.board[x][y] = player

    def get_pawn(self, x: int, y: int) -> int:
        """
        Get the pawn at the specified coordinates.

        Args:
            x (int): The x-coordinate.
            y (int): The y-coordinate.

        Returns:
            int: The player ID at the specified coordinates (0 if empty).
        """
        return self.board[x][y]

    def __str__(self):
        """
        Return a string representation of the board.

        Returns:
            str: The string representation of the board.
        """
        return '\n'.join([' '.join(map(str, row)) for row in self.board])
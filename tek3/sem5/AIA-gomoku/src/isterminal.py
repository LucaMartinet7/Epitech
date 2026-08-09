from .board import Board

def check_in_a_row(line: list[int], n: int) -> tuple[int, int, int, list[int]]:
    """
    Check for exactly n in a row for a player and return:
    - Starting index of the sequence
    - Ending index of the sequence
    - Player ID
    - List of blocking positions

    Args:
        line (list[int]): The line to check.
        n (int): The number of consecutive pawns to check for.

    Returns:
        tuple[int, int, int, list[int]]: A tuple containing the starting index, ending index, player ID, and list of blocking positions.
    """
    count = 0
    last_value = 0
    start_idx = 0
    blocking_positions = []

    for i, value in enumerate(line):
        if value == last_value and value != 0:
            count += 1
            if count == n:
                # Collect possible blocking points
                if i + 1 < len(line) and line[i + 1] == 0:
                    blocking_positions.append(i + 1)  # Space after the sequence
                if start_idx - 1 >= 0 and line[start_idx - 1] == 0:
                    blocking_positions.append(start_idx - 1)  # Space before the sequence
                return (start_idx, i, last_value, blocking_positions)
        else:
            count = 1
            last_value = value
            start_idx = i

    return (0, 0, 0, [])

class IsTerminal:
    def __init__(self, board: Board):
        """
        Initialize the IsTerminal class with the given board.

        Args:
            board (Board): The current board state.
        """
        self.board = board.board
        self.size = board.board_size

    def is_terminal(self) -> tuple[int, int, int]:
        """
        Check if the current board state is terminal (i.e., if there is a winning move or a blocking move).

        Returns:
            tuple[int, int, int]: A tuple containing the row index, column index, and player ID of the terminal move.
        """
        # Check rows
        for row_idx, row in enumerate(self.board):
            result = check_in_a_row(row, 4)
            if result[2]:
                blocking = result[3]
                if blocking:
                    # Return the first blocking move
                    return (row_idx, blocking[0], 0)

        # Check columns
        for col in range(self.size):
            column = [self.board[row][col] for row in range(self.size)]
            result = check_in_a_row(column, 4)
            if result[2]:
                blocking = result[3]
                if blocking:
                    # Return the first blocking move
                    return (blocking[0], col, 0)

        # Check diagonals (top-left to bottom-right)
        for start in range(self.size - 4):
            diag1 = [self.board[start + i][i] for i in range(self.size - start)]
            result = check_in_a_row(diag1, 4)
            if result[2]:
                blocking = result[3]
                if blocking:
                    return (start + blocking[0], blocking[0], 0)

            diag2 = [self.board[i][start + i] for i in range(self.size - start)]
            result = check_in_a_row(diag2, 4)
            if result[2]:
                blocking = result[3]
                if blocking:
                    return (blocking[0], start + blocking[0], 0)

        # Check diagonals (top-right to bottom-left)
        for start in range(self.size - 4):
            diag1 = [self.board[start + i][self.size - 1 - i] for i in range(self.size - start)]
            result = check_in_a_row(diag1, 4)
            if result[2]:
                blocking = result[3]
                if blocking:
                    return (start + blocking[0], self.size - 1 - blocking[0], 0)

            diag2 = [self.board[i][self.size - 1 - start - i] for i in range(self.size - start)]
            result = check_in_a_row(diag2, 4)
            if result[2]:
                blocking = result[3]
                if blocking:
                    return (blocking[0], self.size - 1 - start - blocking[0], 0)

        return (0, 0, 0)
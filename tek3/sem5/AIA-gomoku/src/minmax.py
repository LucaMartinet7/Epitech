import random
from typing import List, Tuple
from .board import Board
from .isterminal import IsTerminal

DIRECTIONS = {
    "top_left": (-1, -1),
    "top": (0, -1),
    "top_right": (1, -1),
    "right": (1, 0),
    "bottom_right": (1, 1),
    "bottom": (0, 1),
    "bottom_left": (-1, 1),
    "left": (-1, 0)
}

class Minimax:
    def __init__(self, size: int):
        """Initialize the Minimax class with a board of given size."""
        self.board = Board(size)
        self.board_size = size

    def minimax(self):
        """Perform the minimax algorithm to determine the best move."""
        x, y = 0, 0
        x, y = maximize(self.board)
        self.board.set_pawn(x, y, 1)
        print(f"{x},{y}", flush=True)
        return 0

    def __str__(self):
        """Return a string representation of the Minimax object."""
        return f"Minimax(board_size={self.board_size})"

def evaluate_board(board: Board, x: int, y: int, pawn_type, eval_check: bool = False):
    """
    Evaluate the board by placing a pawn at (x, y) and return the new board and its score.

    Args:
        board (Board): The current board state.
        x (int): The x-coordinate to place the pawn.
        y (int): The y-coordinate to place the pawn.
        pawn_type (int): The type of pawn to place (1 or 2).
        eval_check (bool): Whether to evaluate the board score.

    Returns:
        Tuple[Board, int]: The new board state and its score.
    """
    score = -1

    size = board.board_size
    tmp = Board(size)

    for i in range(size):
        for j in range(size):
            tmp.set_pawn(i, j, board.get_pawn(i, j))

    tmp.set_pawn(x, y, pawn_type)

    if eval_check:
        if pawn_type == 1:
            oppo = 2
        else:
            oppo = 1
        score = score_board(tmp, pawn_type, oppo)
    return tmp, score

def check_line(line, ally, enemy):
    """
    Check a line (row, column, or diagonal) and calculate the score based on the number of ally pawns.

    Args:
        line (list): The line to check.
        ally (int): The ally pawn type.
        enemy (int): The enemy pawn type.

    Returns:
        int: The score for the line.
    """
    score = 0
    count = 0
    for cell in line:
        if cell == ally:
            count += 1
        elif cell == enemy:
            if count > 0:
                score += count * count
            count = 0
        else:
            if count > 0:
                score += count * count
            count = 0
    if count > 0:
        score += count * count
    return score

def check_rows(board_eval, player):
    """
    Check all rows on the board and calculate the total score for the player.

    Args:
        board_eval (Board): The board to evaluate.
        player (int): The player pawn type.

    Returns:
        int: The total score for the player.
    """
    return sum(check_line(row, player, 3 - player) for row in board_eval.board)

def check_columns(board_eval, player):
    """
    Check all columns on the board and calculate the total score for the player.

    Args:
        board_eval (Board): The board to evaluate.
        player (int): The player pawn type.

    Returns:
        int: The total score for the player.
    """
    size = board_eval.board_size
    return sum(check_line([board_eval.get_pawn(row, col) for row in range(size)], player, 3 - player) for col in range(size))

def check_diagonals(board_eval, player):
    """
    Check all diagonals on the board and calculate the total score for the player.

    Args:
        board_eval (Board): The board to evaluate.
        player (int): The player pawn type.

    Returns:
        int: The total score for the player.
    """
    size = board_eval.board_size
    score = 0
    for d in range(-size + 1, size):
        diag1 = [board_eval.get_pawn(i, i - d) for i in range(max(0, d), min(size, size + d))]
        diag2 = [board_eval.get_pawn(i, size - 1 - i + d) for i in range(max(0, d), min(size, size + d))]
        score += check_line(diag1, player, 3 - player)
        score += check_line(diag2, player, 3 - player)
    return score

def score_board(board_eval: Board, ally: int, enemy: int) -> int:
    """
    Calculate the total score for the board by evaluating rows, columns, and diagonals.

    Args:
        board_eval (Board): The board to evaluate.
        ally (int): The ally pawn type.
        enemy (int): The enemy pawn type.

    Returns:
        int: The total score for the board.
    """
    ally_score = check_rows(board_eval, ally) + check_columns(board_eval, ally) + check_diagonals(board_eval, ally)
    enemy_score = check_rows(board_eval, enemy) + check_columns(board_eval, enemy) + check_diagonals(board_eval, enemy)
    total_score = ally_score - enemy_score
    return total_score

def get_all_possible_moves(board: Board, pawn_type: int = 1) -> Tuple[int, int]:
    """
    Get all possible moves for the given pawn type on the board.

    Args:
        board (Board): The current board state.
        pawn_type (int): The type of pawn to move (1 or 2).

    Returns:
        Tuple[int, int]: The coordinates of a possible move.
    """
    size = board.board_size
    possible_moves: List[Tuple[int, int]] = [
        (x, y) for y in range(size) for x in range(size) if board.get_pawn(x, y) == pawn_type
    ]

    if not possible_moves:
        while True:
            rand_x, rand_y = random.randrange(size), random.randrange(size)
            if board.get_pawn(rand_x, rand_y) == 0:
                return rand_x, rand_y

    while True:
        selected_pawn = random.choice(possible_moves)
        dir_x, dir_y = random.choice(list(DIRECTIONS.values()))
        new_x, new_y = selected_pawn[0] + dir_x, selected_pawn[1] + dir_y

        if 0 <= new_x < size and 0 <= new_y < size and board.get_pawn(new_x, new_y) == 0:
            return new_x, new_y

def maximize(curr_board: Board, depth: int = 0, pawn_type: int = 1) -> Tuple[int, int]:
    """
        Perform the maximize step of the minimax algorithm to determine the best move.

        Args:
            curr_board (Board): The current board state.
            depth (int): The current depth of the search.
            possible_moves (list): The list of possible moves.
            pawn_type (int): The type of pawn to move (1 or 2).

        Returns:
            Tuple[int, int]: The coordinates of the best move.
        """

    winner = IsTerminal(curr_board).is_terminal()
    if winner != (0, 0, 0):
        return winner[0], winner[1]

    if depth >= 4:
        best_score = float('-inf')
        best_move = None

        for x in range(curr_board.board_size):
            for y in range(curr_board.board_size):
                if curr_board.get_pawn(x, y) == 0:  # Check only empty cells
                    _, score = evaluate_board(curr_board, x, y, pawn_type, eval_check=True)
                    if score > best_score:
                        best_score = score
                        best_move = (x, y)

        return best_move if best_move else get_all_possible_moves(curr_board)

    next_moves = []
    for x in range(curr_board.board_size):
        for y in range(curr_board.board_size):
            if curr_board.get_pawn(x, y) == 0:  # Check only empty cells
                new_board, _ = evaluate_board(curr_board, x, y, pawn_type)
                next_moves.append((new_board, x, y))

    best_move = None
    if depth % 2 == 0:
        best_score = float('-inf')
        for board, x, y in next_moves:
            _, score = evaluate_board(curr_board, x, y, pawn_type, eval_check=True)
            if score > best_score:
                best_score = score
                best_move = (x, y)
    else:
        best_score = float('inf')
        for board, x, y in next_moves:
            _, score = evaluate_board(curr_board, x, y, 3 - pawn_type, eval_check=True)
            if score < best_score:
                best_score = score
                best_move = (x, y)

    return best_move if best_move else get_all_possible_moves(curr_board)
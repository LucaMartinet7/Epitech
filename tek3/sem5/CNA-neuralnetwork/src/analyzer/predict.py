import sys
import numpy as np
from .game import ChessPieceEncoder

class Predictor:
    def __init__(self, neural_net):
        self.nn = neural_net
        self.label_to_state = {
            0: 'Check White',
            1: 'Check Black',
            2: 'Checkmate White',
            3: 'Checkmate Black',
            4: 'Stalemate',
            5: 'Nothing'
        }
        self.fen_parser = ChessPieceEncoder()

    def predict_file(self, fen_file):
        """
        Reads a file containing FEN strings, processes each line, and predicts the game state.

        Args:
            fen_file (str): Path to the file containing FEN strings.
        """
        lines = self.read_fen_file(fen_file)
        for line_num, line in enumerate(lines, 1):
            line = line.strip()
            if not line:
                continue

            board = self.fen_parser.encode_fen(line)
            if not self.is_valid_fen(board, line_num):
                continue

            board_array = self.prepare_input(board)
            pred_class = self.nn.predict(board_array)[0]
            predicted_state = self.label_to_state.get(pred_class, "Unknown")
            print(predicted_state)

    def read_fen_file(self, fen_file):
        """
        Reads lines from a FEN file.

        Args:
            fen_file (str): Path to the FEN file.

        Returns:
            list: Lines from the FEN file.
        """
        try:
            with open(fen_file, 'r') as f:
                return f.readlines()
        except Exception as e:
            print(f"Error: Cannot open FEN file: {e}", file=sys.stderr)
            sys.exit(84)

    def is_valid_fen(self, board, line_num):
        """
        Validates the encoded board for a FEN string.

        Args:
            board (list): Encoded board representation.
            line_num (int): Line number in the FEN file.

        Returns:
            bool: True if the board is valid, False otherwise.
        """
        if board is None:
            print(f"Line {line_num}: Invalid FEN")
            return False
        if not self.is_valid_input_size(board):
            print(f"Line {line_num}: Invalid input size for FEN")
            return False
        return True

    def is_valid_input_size(self, board):
        """
        Checks if the input size of the board matches the neural network's expected input size.

        Args:
            board (list): Encoded board representation.

        Returns:
            bool: True if the input size matches, False otherwise.
        """
        return len(board) == self.nn.layer_sizes[0]

    def prepare_input(self, board):
        """
        Prepares the input board for prediction.

        Args:
            board (list): Encoded board representation.

        Returns:
            numpy.ndarray: Reshaped input array for prediction.
        """
        return np.array(board, dtype=np.float32).reshape(1, -1)

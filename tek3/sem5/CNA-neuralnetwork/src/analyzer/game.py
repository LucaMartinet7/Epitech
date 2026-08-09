import numpy as np

class GameStateEncoder:
    """
    Encodes game states into integer values.
    """
    def __init__(self):
        """
        Initializes the encoder with game state mappings.
        """
        self.state_mapping = {
            'Check White': 0,
            'Check Black': 1,
            'Checkmate White': 2,
            'Checkmate Black': 3,
            'Stalemate': 4,
            'Nothing': 5
        }

    def encode_state(self, state):
        """
        Encodes a game state into an integer value.

        Args:
            state (str): The game state to encode.

        Returns:
            int: Encoded integer value for the state.
        """
        return self.state_mapping.get(state, None)

class ChessPieceEncoder:
    """
    Encodes chess pieces and boards into one-hot vectors.
    """
    def __init__(self):
        """
        Initializes the encoder with piece types and their corresponding integer mappings.
        """
        self.piece_types = ['P', 'N', 'B', 'R', 'Q', 'K',
                            'p', 'n', 'b', 'r', 'q', 'k']
        self.piece_to_int = {piece: idx + 1 for idx, piece in enumerate(self.piece_types)}
        self.empty_square = 0
        self.num_features = len(self.piece_types) + 1  # Including empty

    def encode_piece(self, piece):
        """
        Encodes a single chess piece into a one-hot vector.

        Args:
            piece (str): The chess piece to encode.

        Returns:
            np.ndarray: One-hot encoded vector for the piece.
        """
        encoding = np.zeros(self.num_features, dtype=np.float32)
        if piece is None:
            encoding[self.empty_square] = 1.0
        else:
            encoding[self.piece_to_int.get(piece, 0)] = 1.0
        return encoding

    def encode_fen(self, fen_str):
        """
        Encodes a FEN string representing a chess board into a one-hot encoded vector.

        Args:
            fen_str (str): The FEN string to encode.

        Returns:
            list: One-hot encoded vector for the board.
        """
        fen_parts = fen_str.strip().split(' ')
        if len(fen_parts) < 1:
            return None
        piece_placement = fen_parts[0]
        fen_rows = piece_placement.split('/')
        if len(fen_rows) != 8:
            return None
        encoded_board = []
        for fen_row in fen_rows:
            row_encoding = self.encode_row(fen_row)
            if row_encoding is None:
                return None
            encoded_board.extend(row_encoding)
        if len(encoded_board) != 64 * self.num_features:
            return None
        return encoded_board

    def encode_row(self, row):
        """
        Encodes a single row of a chess board into a one-hot encoded vector.

        Args:
            row (str): The row to encode.

        Returns:
            list: One-hot encoded vector for the row.
        """
        board_row = []
        for char in row:
            if char.isdigit():
                for _ in range(int(char)):
                    board_row.extend(self.encode_piece(None))
            elif char.isalpha():
                board_row.extend(self.encode_piece(char))
            else:
                return None
        return board_row
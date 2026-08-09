import sys
import numpy as np
from .game import ChessPieceEncoder, GameStateEncoder

class DatasetParser:
    def __init__(self, dataset_path):
        self.dataset_path = dataset_path
        self.fen_parser = ChessPieceEncoder()
        self.state_encoder = GameStateEncoder()

    def parse(self):
        """
        Parses both the dataset and label files into feature and label arrays.

        Returns:
            tuple: Arrays of features and labels.
        """
        data = self._read_dataset_file()
        labels = self._read_label_file()

        if not data or not labels:
            self._exit_with_error("No valid data or labels found.")

        data = np.array(data, dtype=np.float32)
        labels = np.array(labels, dtype=np.int32)

        self._print_info(labels)
        return data, labels

    def _read_dataset_file(self):
        """
        Reads the dataset file and extracts the features (board representations).

        Returns:
            list: List of feature vectors (boards).
        """
        data = []
        try:
            with open(self.dataset_path, 'r') as f:
                lines = f.readlines()
        except Exception as e:
            self._exit_with_error(f"Cannot open dataset file: {e}")

        for line_num, line in enumerate(lines, 1):
            line = line.strip()
            if not line:
                continue
            parts = line.split()
            if len(parts) < 2:
                self._log_warning(f"Line {line_num} is malformed.")
                continue
            board, _ = self._process_line(parts, line_num)
            if board is not None:
                data.append(board)
        return data

    def _read_label_file(self):
        """
        Reads the label file and extracts the labels for each entry.

        Returns:
            list: List of labels.
        """
        labels = []
        try:
            with open(self.dataset_path, 'r') as f:
                lines = f.readlines()
        except Exception as e:
            self._exit_with_error(f"Cannot open label file: {e}")

        for line_num, line in enumerate(lines, 1):
            line = line.strip()
            if not line:
                continue
            parts = line.split()
            if len(parts) < 1:
                self._log_warning(f"Line {line_num} is malformed.")
                continue
            _, label = self._process_line(parts, line_num)
            if label is not None:
                labels.append(label)
        return labels

    def _process_line(self, parts, line_num):
        """
        Processes a single line of data from the dataset.

        Args:
            parts (list): The parts of the line (board + label).
            line_num (int): The line number for error reporting.

        Returns:
            tuple: Processed board and label.
        """
        state_val = self._extract_state(parts, line_num)
        if state_val is None:
            return None, None

        fen_str = self._extract_fen(parts)

        board = self.fen_parser.encode_fen(fen_str)
        if board is not None:
            return board, state_val
        else:
            self._log_warning(f"Invalid FEN at line {line_num}.")
        return None, None

    def _extract_state(self, parts, line_num):
        """
        Extracts the state from the parts of a line.

        Args:
            parts (list): The parts of the line split by spaces.
            line_num (int): The line number for error reporting.

        Returns:
            The encoded state value, or None if invalid.
        """
        state_val = None
        if len(parts) >= 3:
            state_val = self._encode_state(" ".join(parts[-2:]))
            if state_val:
                return state_val
        if state_val is None:  # Fallback to one-word state
            state_val = self._encode_state(parts[-1])

        if state_val is None:
            self._log_warning(f"Unknown state at line {line_num}.")
        return state_val

    def _extract_fen(self, parts):
        """
        Extracts the FEN string from the parts of a line.

        Args:
            parts (list): The parts of the line split by spaces.

        Returns:
            The FEN string.
        """
        if len(parts) >= 3:
            return " ".join(parts[:-2])
        else:
            return " ".join(parts[:-1])

    def _encode_state(self, state):
        """
        Encodes the game state into a numerical value.

        Args:
            state (str): The state string.

        Returns:
            The encoded state value.
        """
        return self.state_encoder.encode_state(state)

    def _log_warning(self, message):
        """
        Logs a warning message to stderr.

        Args:
            message (str): The warning message.
        """
        print(f"Warning: {message}", file=sys.stderr)

    def _exit_with_error(self, message):
        """
        Exits the program with an error message.

        Args:
            message (str): The error message.
        """
        print(f"Error: {message}", file=sys.stderr)
        sys.exit(84)

    def _print_info(self, labels):
        """
        Prints information about the dataset and class distribution.

        Args:
            labels (list): The labels array.
        """
        print(f"Parsed {len(labels)} training examples.")
        class_counts = np.bincount(labels, minlength=6)
        print("Class distribution:", class_counts)